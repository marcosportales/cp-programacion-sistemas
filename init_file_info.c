#include "file_log.h"
#include <sys/types.h>

void init_file_info(pfile *file, char *c)
{
    int i;
    (*file)->tot_arch = files_to_process(c);
    (*file)->arch = (char **)malloc((*file)->tot_arch * sizeof(char *));
    (*file)->time_mod = (time_t **)malloc((*file)->tot_arch * sizeof(time_t *));
    (*file)->user_mod = (uid_t **)malloc((*file)->tot_arch * sizeof(uid_t *));
    (*file)->check_mod = (int *)malloc((*file)->tot_arch * sizeof(int));
    for (i = 0; i < (*file)->tot_arch; i++)
    {
        (*file)->arch[i] = (char *)malloc(MAXLEN * sizeof(char));
        (*file)->time_mod[i] = (time_t *)malloc(sizeof(time_t));
        (*file)->user_mod[i] = (uid_t *)malloc(sizeof(uid_t));
        (*file)->check_mod[i] = 0;
    }
}