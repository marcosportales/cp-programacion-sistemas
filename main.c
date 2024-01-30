#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

void monitorFile(const char* filename, const char* logfilename) {
    struct stat oldStat;
    stat(filename, &oldStat);

    while (1) {
        struct stat newStat;
        stat(filename, &newStat);

        if (newStat.st_mtim.tv_sec != oldStat.st_mtim.tv_sec ||
            newStat.st_mtim.tv_nsec != oldStat.st_mtim.tv_nsec) {
            time_t rawtime = newStat.st_mtim.tv_sec;
            struct tm * timeinfo = localtime(&rawtime);

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

        sleep(1);
    }
}

int main(int argc, char **argv) {
    monitorFile(argv[1], argv[2]);
    return 0;
}
