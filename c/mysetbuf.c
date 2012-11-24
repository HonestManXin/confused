#include "header.h"


//print the basic info of FILE
void pr_stdio(char *name,FILE *fp)
{
    printf ( "stream name = %s\n",name );
    
    if(fp->_flags & __SNBF)
        printf ( "unbuffered " );
    else if(fp->_flags & __SLBF)
        printf ( "line buffered " );
    else
        printf ( "full buffered " );

    printf ( " buffer size= %d \n",-fp->_lbfsize);
}

//get set type from FILE 
int get_fptype(FILE *fp)
{
    if(fp->_flags & __SNBF)
        return _IONBF;
    else if(fp->_flags & __SLBF)
        return _IOLBF;
    return _IOFBF;
}

void mysetbuf(FILE *fp,char *buf)
{
    if(buf == NULL)
    {
        setvbuf(fp,NULL,_IONBF,0);
    }
    else
    {
        setvbuf(fp,buf,get_fptype(fp),BUFSIZ);
    }
}


int main(int argc,char *argv[])
{

    mysetbuf(stdout,NULL);
    pr_stdio("stdout nobuf",stdout);
    return 0;
}

