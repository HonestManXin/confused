#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void intr(int signo)
{
    sleep(1);
    if(signo == SIGINT)
        printf ( "%d ctrl+c \n",signo );
}

int main(int argc,char *argv[])
{
    if(signal(SIGINT,intr)<0)
    {
        printf ( "sinal called error\n" );
        exit(-1);
    }
    kill(getpid(),SIGINT);
    printf ( "kill over\n" );
    return 0;
}

