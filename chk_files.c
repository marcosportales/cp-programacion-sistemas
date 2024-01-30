#include "file_log.h"
#include <sys/stat.h>

void chk_files(pfile *file)
{
    int i;
    for (i = 0; i < (*file)->tot_arch; i++)
    {
        if ((*file)->check_mod[i] == 0)
        {
            if (fmod_status((*file)->arch[i]) != *((*file)->time_mod[i]))
            {
                *((*file)->time_mod[i]) = fmod_status((*file)->arch[i]);
                *((*file)->user_mod[i]) = user_status((*file)->arch[i]);
                (*file)->check_mod[i] = 1;
            }
        }
    }
}