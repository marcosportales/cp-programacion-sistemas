#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define CONFIG_FILE "/etc/sec-info/file.conf"
#define LOG_FILE "/etc/sec-info/log.txt"
#define CHECK_INTERVAL 10

typedef struct {
    char *path;
} Path;
int lim = 0;

Path *readConfigFile() {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Path *paths = malloc(sizeof(Path));
    char line[256];
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strchr(line, '\n')) {
            line[strlen(line) - 1] = '\0';
        }
        lim++;
        paths[i].path = strdup(line);

        i++;
        paths = realloc(paths, (i + 1) * sizeof(Path));
    }

    fclose(file);
    return paths;
}

void checkFile(Path file) {
    struct stat attrs;
    if (stat(file.path, &attrs) != 0) {
        perror("Error getting file attributes");
        exit(EXIT_FAILURE);
    }
    time_t temp = attrs.st_mtime;
    printf("File %s last modified time: %s\n", file.path, ctime(&temp));
    // printf("%ld\n", attrs.st_mtime > time(NULL) - CHECK_INTERVAL);
    if (attrs.st_mtime > time(NULL) - CHECK_INTERVAL) {
        FILE *logFile = fopen(LOG_FILE, "a");
        if (logFile == NULL) {
            perror("Error opening log file");
            exit(EXIT_FAILURE);
        }

        time_t t = time(NULL) - CHECK_INTERVAL;
        char *fecha = ctime(&t);

#ifdef _WIN32
        char nombre[256];
        DWORD tam = sizeof(nombre);
        BOOL resultado = GetUserName(nombre, &tam);
        if (resultado)
        {
            fprintf(logFile, "File %s was modified at time %s by user %s\n", file.path, fecha, nombre);
        }
        else
        {
            fprintf(logFile, "File %s was modified at time %s but no user found\n", file.path, fecha);
        }
#else
        fprintf(logFile, "File %s was modified at time %s by user %s\n", file.path, fecha, getlogin());
#endif
        fclose(logFile);


    }
}

int main() {
    Path *filesToCheck = readConfigFile();

    while (1) {
        for (int i = 0; i < lim; i++) {
            checkFile(filesToCheck[i]);
            // break;
        }

        sleep(CHECK_INTERVAL);
    }
}
