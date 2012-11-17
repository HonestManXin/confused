#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    char *buf = (char*)malloc(sizeof(10));
    printf ( "buf lenghth is : %ld\n", sizeof(buf) );
    return 0;
}
