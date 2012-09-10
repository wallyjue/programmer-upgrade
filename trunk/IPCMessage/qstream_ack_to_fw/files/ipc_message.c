/*******************************************************************************
* All Rights Reserved, Copyright @ Quanta Computer Inc. 2011
* File Name: ipc_message.h
* File Mark:
* Content Description: common IPC API
* Other Description:
* Version: 1.0
* Author: Paul Weng
* Date: 2011/08/05
* History:
*   1.2011/08/05 draft
*******************************************************************************/
/* =============================================================================
                                Included headers
============================================================================= */
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


/* =============================================================================
                                    Constants
============================================================================= */
#define MAX_PACKET_LEN      1024
#define IPC_MESSAGE_IP      "127.0.0.1"
#define IPC_TEST_APP        0


/* =============================================================================
                                    Macros
============================================================================= */
#define container_of(ptr, type, member) ({ \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type,member) );})


/* =============================================================================
                                    Types
============================================================================= */
typedef struct _IpcMessage
{
    int     command;
    int     para_size;
    char    para[MAX_PACKET_LEN-sizeof(int)-sizeof(int)];
} IpcMessage;


typedef struct _IpcServer
{
    IpcSocket   socket;
    Execfp      exec_cb;
} IpcServer;


/* =============================================================================
                                Private data
============================================================================= */
static pthread_t    g_server_tid = 0;
static int          g_server_flag = 0;


/* =============================================================================
                        Private function declarations
============================================================================= */
static void* Ipc_Server_Run(void* server);


/* =============================================================================
                                Implement Start
============================================================================= */
/* =============================================================================
* Function: Ipc_Server_Run
* Describe: polling ipc client request
* Input: data - ipc server data
* Output: none
* Return: none
* History:
*   1.2011/08/05 draft
============================================================================= */
static void* Ipc_Server_Run(void* data)
{
    IpcServer*          server = (IpcServer*)data;
    fd_set              readfds;
    struct sockaddr_in	addr;
    IpcMessage*         msg = NULL;
    char                buffer[MAX_PACKET_LEN];
    int                 recv_len = 0;


	extern void log_pid(const char* func, pid_t tid);
	log_pid(__FUNCTION__, gettid());
	
    if (server)
    {
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(server->socket.port);
        addr.sin_addr.s_addr = htonl(INADDR_ANY);

		int count = 0;
        while (bind(server->socket.fd, (const struct sockaddr*)&addr, sizeof(addr)) < 0) {
			perror("IPC Bind Error, Retry...");
			count++;
			if (count >=3) {
				perror("IPC Bind Error, Exit the Program"); 
				exit(0);
			}
			sleep(1);	
		}
		printf("IPC Bind Success, port = %d\n", addr.sin_port);
        
        FD_SET(server->socket.fd, &readfds);
    }
    else
    {
        return "Ipc_Server_Run Failure";
    }
    
    g_server_flag = 1;
    while (1 == g_server_flag)
    {
        if (-1 == select(server->socket.fd+1, &readfds, NULL, NULL, NULL))
        {
            printf("\nIpc_Server_Run error");
            return NULL;
        }

        if (FD_ISSET(server->socket.fd, &readfds))
        {
            memset(buffer, 0, MAX_PACKET_LEN);
            recv_len = recvfrom(server->socket.fd, buffer, MAX_PACKET_LEN, 0, 0, 0);
            if (recv_len)
            {
                msg = (IpcMessage*)buffer;
                msg->command = ntohl(msg->command);
                msg->para_size = ntohl(msg->para_size);
                memcpy(msg->para, &buffer[sizeof(int)+sizeof(int)], msg->para_size);
                
                #if IPC_TEST_APP
                fprintf(stderr, "\nIpc_Server_Run recv_len = %d", recv_len);
                fprintf(stderr, "\nIpc_Server_Run command = %d", msg->command);
                fprintf(stderr, "\nIpc_Server_Run para_size = %d", msg->para_size);
                fprintf(stderr, "\nIpc_Server_Run para = %s\n", msg->para);
                #endif
                
                if (server->exec_cb)
                {
                    server->exec_cb(msg->command, msg->para);
                }                
            }
        }
    } 
    
    return "Ipc_Server_Run Exit";
}


/* =============================================================================
* Function: Ipc_Server_Init
* Describe: create a IPC server thread to polling ipc client request
* Input: listen_port - ipc server listen port
*        exec_cb - execute callback function
* Output: none
* Return: server sock, return NULL means initialize failure
* History:
*   1.2011/08/05 draft
============================================================================= */
extern IpcSocket* Ipc_Server_Init(int listen_port, Execfp exec_cb)
{
    IpcServer*  server = NULL;
    int         ret = 0;


    server = (IpcServer*)malloc(sizeof(IpcServer));
    if (NULL == server)
    {
        printf("\nIpc_Server_Init error");
        return NULL;
    }

    memset(server, 0, sizeof(IpcServer));
    server->socket.fd = socket(AF_INET, SOCK_DGRAM, 0);
    server->socket.port = listen_port;
    server->exec_cb = exec_cb;

    if (server->socket.fd > 0)
    {
        ret = pthread_create(&g_server_tid, NULL, Ipc_Server_Run, (void*)server);
    }
    else
    {
        free(server);
        return NULL;
    }

    return &server->socket;
}


/* =============================================================================
* Function: Ipc_Client_Init
* Describe: create a ipc clinet socket
* Input: server_port - ipc server listen port
* Output: none
* Return: clietn socket, return NULL means initialize failure
* History:
*   1.2011/08/05 draft
============================================================================= */
extern IpcSocket* Ipc_Client_Init(int server_port)
{
    IpcSocket*   client = NULL;
    
    
    client = (IpcSocket*)malloc(sizeof(IpcSocket));
    if (client)
    {
        client->fd = socket(AF_INET, SOCK_DGRAM, 0);
        client->port = server_port;
        return client;
    }

    return NULL;
}


/* =============================================================================
* Function: Ipc_Send
* Describe: send an encapsulated data to IPC server
* Input: client - client socket
*        commnad - request commnad
*        para - encapsulated data
*        para_size - encapsulated data size
* Output: none
* Return: send data size
* History:
*   1.2011/08/05 draft
============================================================================= */
extern int Ipc_Send(IpcSocket* client, int command, void* para, int para_size)
{
    struct sockaddr_in	addr;
    IpcMessage          msg;
    int                 len = 0;
    int                 send_len = 0;
    
    
    if (NULL == client)
    {
        return 0;
    }
    
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(client->port);
    addr.sin_addr.s_addr = inet_addr(IPC_MESSAGE_IP);

    memset(&msg, 0, sizeof(IpcMessage));
    msg.command = htonl(command);
    msg.para_size = htonl(para_size);

    memcpy(msg.para, para, para_size);
    len = sizeof(int) + sizeof(int) + para_size;
    send_len = sendto(client->fd, &msg, len, 0, (const struct sockaddr*)&addr, sizeof(addr));
    #if IPC_TEST_APP
    fprintf(stderr, "\nIpc_Send send_len = %d", send_len);
    #endif

    return send_len;
}


/* =============================================================================
* Function: Ipc_Server_Destory
* Describe: destory IPC server thread and release resource
* Input: socket - server socket
* Output: none
* Return: none
* History:
*   1.2011/08/05 draft
============================================================================= */
extern void Ipc_Server_Destroy(IpcSocket* server_socket)
{
    IpcServer*  server = NULL;
    
    
    if (server_socket)
    {
        close(server_socket->fd);
        server = container_of(server_socket, IpcServer, socket);
        server->exec_cb = NULL;
        free(server);
    }

    g_server_flag = 0;
    pthread_join(g_server_tid, NULL);

    return;
}


/* =============================================================================
* Function: Ipc_Client_Destory
* Describe: release client resource
* Input: client - client socket
* Output: none
* Return: none
* History:
*   1.2011/08/05 draft
============================================================================= */
extern void Ipc_Client_Destroy(IpcSocket* client)
{
    close(client->fd);
    client->fd = 0;
    client->port = 0;
    free(client);
    
    return;
}
