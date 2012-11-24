#include "header.h"

int main(int argc,char *argv[])
{
    char buf[200]={0};
    int i=0;
    FILE *fp;
    fp = fopen("out.txt","r");

    fgets(buf,200,fp);
    printf ( "%s ",buf );
    fclose(fp);

    //gets不将输入的换行符添加进来
    // gets(buf);
    //printf ( "%s ",buf );

    fp = fopen("out.txt","a+");
    fputs(buf,fp);
    fclose(fp);

    fp = fopen("out.txt","w");
    fputs("with \n",fp);
    fclose(fp);

    fp = fopen("out.txt","a+");
    fputs("next",fp);
    fclose(fp);

    puts(buf);

    for(i = 0 ;i<sizeof(buf);i++)
        if(buf[i] == '\n')
            printf ( "has line break \n" );

    return 0;
}
