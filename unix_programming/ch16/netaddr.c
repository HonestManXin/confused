#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

void printf_socketype(struct addrinfo *aip)
{
    printf ( "type  " );
    switch(aip->ai_socktype) {
        case SOCK_STREAM:
            printf ( "stream\n" );
            break;
        case SOCK_DGRAM:
            printf ( "dgram\n" );
            break;
        case SOCK_SEQPACKET:
            printf ( "seqpacket\n" );
            break;
        case SOCK_RAW:
            printf ( "raw\n" );
            break;
        default:
            printf ( "unknown type\n" );
    }
}

void print_proto_name(struct addrinfo *info)
{
    printf ( "proto:%d  cannoname:%s\n",info->ai_protocol,info->ai_canonname );
}

void print_sockaddr_info(struct sockaddr_in *sinp)
{
    const char *addr;
    char abuf[INET_ADDRSTRLEN];
    uint32_t addr_int;
    addr_int = ntohl((sinp->sin_addr).s_addr);
    printf ( "addr_int number:%d \n",addr_int );
    addr = inet_ntop(AF_INET,&sinp->sin_addr,abuf,INET_ADDRSTRLEN);
    printf ( "address:%s   port:%d\n",addr,ntohs(sinp->sin_port) );
    printf ( "addr:0x%lx abuf:0x%lx\n",(unsigned long)addr,(unsigned long) abuf);
}

void myhostent()
{
    struct hostent *ent;
    char **names;
    int i = 0 ;
    ent = gethostent();
    printf ( "h_name:%s  \n",ent->h_name );
    names = ent->h_aliases;
    if(names && names[i])
    {
        printf ( "names:%s \n",names[i] );
        i++;
    }
    i = 0;
    names = ent->h_addr_list;
    if(names && names[i])
    {
        printf ( "names:%s \n",names[i] );
        i++;
    }
}

int main(int argc,char *argv[])
{
    struct addrinfo *ailist,*aip;
    struct addrinfo hint;
    struct sockaddr_in *sinp;
    
    int lsd,rsd;
    int errno;

    lsd = socket(AF_INET,SOCK_STREAM,0); //connect to googl.com
    hint.ai_flags = AI_CANONNAME;
    hint.ai_family = AF_INET;
    hint.ai_addr = 0;
    hint.ai_addrlen = 0;
    hint.ai_canonname = 0;
    hint.ai_protocol = 0;
    hint.ai_socktype = 0;
    hint.ai_next = 0;

    if((errno=getaddrinfo("www.google.com","http",&hint,&ailist))<0)
    {
        printf("%s\n",gai_strerror(errno));
        exit(-1);
    }
    printf_socketype(ailist);
    print_proto_name(ailist);
    sinp = (struct sockaddr_in *)ailist->ai_addr;
    print_sockaddr_info(sinp);
    myhostent();
    return 0;
}



