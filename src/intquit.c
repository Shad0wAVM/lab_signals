/* intquit.c

   Catch the SIGINT and SIGQUIT signals, which are normally generated
   by the control-C (^C) and control-\ (^\) keys respectively.
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void sigHandler(int sig) {
    static int count = 0;

    /* UNSAFE: This handler uses non-async-signal-safe functions (printf(), exit();) */

    if (sig == SIGINT) {
        /* In some systems, after the handler call the signal gets reverted
           to SIG_DFL (the default action associated with the signal).
           So we set the signal handler back to our function after each trap. */
        if (signal(SIGINT, sigHandler) == SIG_ERR)
            exit(EXIT_FAILURE);
        count++;
        printf("Caught SIGINT (%d)\n", count);
        return;                 /* Resume execution at point of interruption */
    }

    /* Must be SIGQUIT - print a message and terminate the process */

    printf("Caught SIGQUIT - that's all folks!\n");
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
    /* Establish same handler for SIGINT and SIGQUIT.
       Here we use the simple signal() API to establish a signal handler. */

    if (signal(SIGINT, sigHandler) == SIG_ERR)
        exit(EXIT_FAILURE);
    if (signal(SIGQUIT, sigHandler) == SIG_ERR)
        exit(EXIT_FAILURE);

    for (;;)                    /* Loop forever, waiting for signals */
        pause();                /* Block until a signal is caught */
}