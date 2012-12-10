#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t gid,pid;
    pid_t sid;
    gid = getpgrp();
    pid= getpid();

    printf ( "pid=%d gid=%d \n",pid,gid );
    sid = getsid(0);
    printf ( "sid = %d \n",sid );
    return 0;
}
