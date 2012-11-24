#include "header.h"


int main(int argc,char *argv[])
{
    FILE *fp;
    fp = freopen("out.txt","a+",stdout);
    printf ( "%d\n",fileno(fp) );
    printf ( "freopen on stdout test\n" );
    return 0;
}
