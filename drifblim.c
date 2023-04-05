#include<stdbool.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h>
#include<unistd.h>

#define INTERVAL 60u

int
main(void)
{
    while(true) {
        wait(NULL);
        if (errno == ECHILD) {
            sleep(INTERVAL);
        }
    }
}
