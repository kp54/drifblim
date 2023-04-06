#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int pid = fork();
    if (pid != 0)
    {
        exit(EXIT_SUCCESS);
    }

    sleep(1);
    exit(EXIT_SUCCESS);
}
