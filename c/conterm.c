#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t id;
    pid_t sid;
    pid_t fgid;
    if((id = fork())<0)
    {
        printf ( "fork error\n" );
        exit(-1);
    }
    else if(id >0) //parent
    {
        printf ( "parent: pid=%d sid=%d pgid=%d\n",getpid(),getsid(0),getpgrp() );
        wait(NULL);
        fgid = tcgetpgrp(0);
        printf ( "foregid = %d \n",fgid );
    }
    else
    {
        setsid();
        printf ( "son: pid=%d sid=%d pgid=%d\n",getpid(),getsid(0),getpgrp() );
        fgid = tcgetpgrp(0);
        printf ( "foregid = %d \n",fgid );
    }
    return 0;
}
