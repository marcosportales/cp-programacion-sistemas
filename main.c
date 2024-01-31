#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <malloc.h>
#include <stdlib.h>
#include <sys/stat.h>

#define CONFIG_FILE "/home/victor/CLionProjects/cp-programacion-sistemas/file.conf"
#define LOG_FILE "/home/victor/CLionProjects/cp-programacion-sistemas/log.txt"
#define CHECK_INTERVAL 1

typedef struct {
    char* path;
} Path;

Path* readConfigFile() {
    FILE* file = fopen(CONFIG_FILE, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Path* paths = malloc(sizeof(Path));
    char line[256];
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
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

    printf("Last modified time: %ld\n", attrs.st_mtime);

    if (attrs.st_mtime > time(NULL) - CHECK_INTERVAL) {
        FILE* logFile = fopen(LOG_FILE, "a");
        if (logFile == NULL) {
            perror("Error opening log file");
            exit(EXIT_FAILURE);
        }

        fprintf(logFile, "File %s was modified at time %ld by user %s\n", file.path, time(NULL) - CHECK_INTERVAL,
                getlogin());
        fclose(logFile);
    }
}

int main() {
    Path* filesToCheck = readConfigFile();

    while (1) {
        for (int i = 0; filesToCheck[i].path != NULL; i++) {
            checkFile(filesToCheck[i]);
        }

        sleep(CHECK_INTERVAL);
    }

    return 0;
}
