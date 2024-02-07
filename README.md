# Tarea Evaluativa de Programacion de sistemas

## Orientaciones

Se propone la creación de un servicio denominado `file_chkd`. Este servicio tiene como objetivo principal la verificación de un conjunto de archivos. La definición de este conjunto se realiza a través de un archivo de configuración llamado `file.conf`, ubicado en el directorio `/etc/sec-info/`.

El servicio `file_chkd` está diseñado para comprobar si los archivos han sufrido modificaciones cada 10 segundos. En caso de detectar cambios, el servicio registrará el autor de dichas modificaciones. Este proyecto ha sido desarrollado para ser compatible con los sistemas operativos Windows (mediante WSL2) y Linux.

# Pasos a seguir

- Para iniciar la aplicación en Linux, se debe ejecutar el script `checkf_make_all.sh`.
- Usted luego debe abrir la carpeta `/etc/sec-info/` y agregar los archivos que desea monitorear en el archivo `file.conf`.
- Los cambios serán agregados al archivo `log.txt`.

## Integrantes

- Victor Palmero Valdes
- Jose Lazaro Diaz Estive
- Marcos Portales Ramos
