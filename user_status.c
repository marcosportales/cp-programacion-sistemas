#include "file_log.h"
#include <sys/types.h>
#include <sys/stat.h>

uid_t user_status(char *c)
{
    struct stat attrib;
    if (stat(c, &attrib) != 0)
    {
        return -1; // Devuelve -1 si hay un error
    }
    return attrib.st_uid; // Devuelve el id del usuario que modificó el archivo
}
