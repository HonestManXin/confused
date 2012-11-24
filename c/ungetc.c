#include "header.h"

int main(int argc,char *argv[])
{
    int ch;
    char c;
    ch = 'a';
    ungetc(ch,stdin);
    ch ++;
    ungetc(ch,stdin);
    c = getc(stdin);
    printf ( "unget get ch %c \n",c );
    c = getc(stdin);
    printf ( "unget get ch %c \n",c );
    return 0;
}
