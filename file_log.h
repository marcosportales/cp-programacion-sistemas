#include <time.h>
// #include <sys/stat.h>
// #include <unistd.h>
#include <sys/types.h>
#ifndef _FILE_LOG
#define _FILE_LOG
#define MAXLEN 255

typedef struct
{
    int tot_arch;      // Cantidad de archivos a verificar
    char **arch;       // Nombre de los archivos
    time_t **time_mod; // Fecha de la última modificación
    uid_t **user_mod;  // ID del usuario que modificó el archivo
    int *check_mod;    // Flag que indica si fue modificado
} file_info;

typedef file_info *pfile;

// Determina la cantidad de archivos a verificar
int files_to_process(char *c);
// Obtiene la fecha de la última modificación de un archivo
time_t fmod_status(char *c);
// Obtiene el id del usuario que ha modificado el archivo
uid_t user_status(char *c);
// Inicializa la estructura file_info con la información de cada archivo a procesar
void init_file_info(pfile, char *c);
// Verifica si alguno de los archivos definidos han sido modificados
void chk_files(pfile);
#endif