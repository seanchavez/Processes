// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

    printf("hello world (pid: %d)\n", (int) getpid());
    // ------------------------------------------------ child process starts executing here
    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello, child here (pid: %d), x is %d\n", (int) getpid(), x);
        x++;
        printf("child here, x is %d\n", x);
    } else {
        printf("hello, parent here (pid: %d) of child %d, x is %d\n", (int) getpid(), rc, x);
        x--;
        printf("parent here, x is %d\n", x);
    }


    return 0;
}
