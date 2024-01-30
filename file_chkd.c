#include <stdio.h>
#include <unistd.h>

#define INTERVAL 36000

int main () {

    while (1) {
        sleep(INTERVAL);
    }

    return 0;
}