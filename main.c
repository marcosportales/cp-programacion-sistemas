#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>

void monitoringFiles(const char* filename, const char* logfilename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening config file");
        return;
    }

    char line[256];
    while (1) {
        while (fgets(line, sizeof(line), file)) {
            size_t len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[--len] = '\0';
            }

            struct stat oldStat;
            stat(filename, &oldStat);

            struct stat newStat;
            stat(line, &newStat);

            if (newStat.st_mtim.tv_sec != oldStat.st_mtim.tv_sec ||
                newStat.st_mtim.tv_nsec != oldStat.st_mtim.tv_nsec) {
                time_t rawtime = newStat.st_mtim.tv_sec;
                struct tm *timeinfo = localtime(&rawtime);

                printf("File %s was modified by %s at %s", filename, getlogin(), asctime(timeinfo));

                FILE *logfile = fopen(logfilename, "a");
                if (logfile == NULL) {
                    perror("Error opening log file");
                    return;
                }

                fprintf(logfile, "File %s was modified by %s at %s", filename, getlogin(), asctime(timeinfo));
                fclose(logfile);

                oldStat = newStat;
            }
        }
            sleep(10);
    }
}

int main() {
    monitoringFiles("/etc/sec-info/file.conf", "/var/log/file_chkd.log");
    return 0;
}
