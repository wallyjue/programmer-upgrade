#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "ipc_message.h"


int exec(int command, void* para)
{
    printf("\ncommand = %d", command);
    printf("\npara = %s\n", (char*)para);
    
    return 0;
}


int main(int argc, char* argv[])
{
    IpcSocket* qstream_server = NULL;

  
    qstream_server = Ipc_Server_Init(10000, exec);
    if (NULL == qstream_server)
    {
        printf("\n qstream_server Ipc_Server_Init failure");
    }

    while(1)
    {
        sleep(60);
    }
    Ipc_Server_Destory(qstream_server);

    return 0;
}
