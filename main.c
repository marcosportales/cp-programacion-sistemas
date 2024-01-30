#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define INTERVAL 3600

void o_mem_rate()
{
    FILE *fp, *log;
    double mem_total, mem_free, mem_rate, mem_used;

    time_t time_actual;

    struct tm *time_info;
    char timestamp[20];
    
    fp = fopen("proc/meminfo", "r");
    log = fopen("./mem.log", "a+");
    fscanf(fp, "Mem Tot: %lf KB\n", &mem_total);
    fscanf(fp, "Mem Free: %lf KB\n", &mem_free);

    mem_used = mem_total - mem_free;
    mem_rate = (mem_used / mem_total) * 100;
    time(&time_actual);
    time_info = localtime(&time_actual);
    strftime(timestamp, 20, "%y - %m - %d - %H:%M:%S", time_info);
    fprintf(log, "[%s] Mem Rate: %lf\n", timestamp, mem_rate);
    fclose(fp);
}

int main()
{
    while (1)
    {
        o_mem_rate();
        sleep(INTERVAL);
    }
    return 0;
}