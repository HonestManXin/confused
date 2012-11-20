#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int mydup(int fd,int newfd)
{
    int tep_fd;
    int res_fd;
    if(fd == newfd)
        return fd;
    close(newfd);
    tep_fd = dup(fd);
    if(tep_fd == newfd)
        return newfd;
    else if(tep_fd < newfd)
    {
        res_fd = mydup(fd,newfd);
        close(tep_fd);
        if(res_fd >0)
            return res_fd;
        else
            return -1;
    }
    else
    {
        res_fd = mydup(fd,newfd);
        close(tep_fd);
        if(res_fd >0)
            return res_fd;
        else 
            return -1;
    }
    return -1;
}

int main(int argc,char *argv[])
{
    char buf[] = "test success\n";
    int fd = mydup(0,5);

    write(fd,buf,sizeof(buf));
    printf ( "%d \n",fd );
    return 0;
}
