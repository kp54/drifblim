#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void terminate(int signo)
{
    exit(EXIT_SUCCESS);
}

int main(void)
{
    sigaction(SIGTERM, &(struct sigaction){.sa_handler = &terminate}, NULL);

    while (true)
    {
        sleep(143);
    }
}
