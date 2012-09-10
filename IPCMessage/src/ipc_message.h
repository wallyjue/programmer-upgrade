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
#ifndef __IPC_MESSAGE_H
#define __IPC_MESSAGE_H


#ifdef __cplusplus
extern "C" {
#endif


/* =============================================================================
                                    Constants
============================================================================= */
#define QSTREAM_SERVER		        60000
#define SIP_SERVER                  60002
#define FRAMEWORK_SERVER	        60004

#define FRAMEWORK_FOR_DECT_SERVER	60006


/* =============================================================================
                                    Types
============================================================================= */
typedef int (*Execfp)(int command, void* para);

typedef struct _IpcSocket
{
    int fd;     /* socket descritor */
    int port;   /* socket listen port */
} IpcSocket;


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
IpcSocket* Ipc_Server_Init(int listen_port, Execfp exec_cb);


/* =============================================================================
* Function: Ipc_Client_Init
* Describe: create a ipc clinet socket
* Input: server_port - ipc server listen port
* Output: none                             
* Return: clietn socket, return NULL means initialize failure
* History: 
*   1.2011/08/05 draft
============================================================================= */
IpcSocket* Ipc_Client_Init(int server_port);


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
int Ipc_Send(IpcSocket* client, int commnad, void* para, int para_size);


/* =============================================================================
* Function: Ipc_Server_Destory
* Describe: destory IPC server thread and release resource 
* Input: server - server socket
* Output: none
* Return: none
* History: 
*   1.2011/08/05 draft
============================================================================= */
void Ipc_Server_Destroy(IpcSocket* server);


/* =============================================================================
* Function: Ipc_Client_Destory
* Describe: release client resource 
* Input: client - client socket
* Output: none
* Return: none
* History: 
*   1.2011/08/05 draft
============================================================================= */
void Ipc_Client_Destroy(IpcSocket* client);


#ifdef __cplusplus
}
#endif

#endif /* __IPC_MESSAGE_H */

