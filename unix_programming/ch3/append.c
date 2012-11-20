#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
    int fd = open("test.data",O_APPEND|O_RDWR);
    char buf[] = "append data";
    char read_buf[10]="\0";
    lseek(fd,SEEK_SET,0);
    read(fd,read_buf,6);
    read_buf[6] = '\0';
    printf ( "read: %s\n",read_buf );

    write(fd,buf,sizeof(buf));
    return 0;
}
