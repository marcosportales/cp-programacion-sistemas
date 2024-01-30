#include <time.h>
#include <sys/stat.h>

time_t fmod_status(char *c)
{
    struct stat attrib;
    if (stat(c, &attrib) != 0)
    {
        return -1; // Devuelve -1 si hay un error
    }
    return attrib.st_mtime; // Devuelve la hora de la última modificación
}