#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int ret, signo;
    sigset_t ss;

    sigemptyset(&ss);
    sigaddset(&ss, SIGCHLD);
    sigaddset(&ss, SIGTERM);

    sigprocmask(SIG_BLOCK, &ss, NULL);

    while (true)
    {
        ret = sigwait(&ss, &signo);
        if (ret != 0)
        {
            exit(EXIT_FAILURE);
        }

        if (signo == SIGTERM)
        {
            exit(EXIT_SUCCESS);
        }

        if (signo == SIGCHLD)
        {
            while (true)
            {
                wait(NULL);
                if (errno == ECHILD)
                {
                    break;
                }
            }
        }
    }
}
