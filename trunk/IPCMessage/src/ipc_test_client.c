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


int main(int argc, char* argv[])
{
    IpcSocket* sip_client = NULL;
    IpcSocket* framework_client = NULL;
    
   
    sip_client = Ipc_Client_Init(10000);
    if (NULL == sip_client)
    {
        printf("\n sip_client Ipc_Client_Init failure");
    }

    
    framework_client = Ipc_Client_Init(10000);
    if (NULL == framework_client)
    {
        printf("\n framework_client Ipc_Client_Init failure");
    }

    Ipc_Send(sip_client, 1, "SIP CLENT TEST", 15);
    Ipc_Send(framework_client, 2, "FRAMEWORK CLENT TEST", 21);

    Ipc_Client_Destory(sip_client);
    Ipc_Client_Destory(framework_client);

    return 0;
}
