#ifndef IPC_SIP_SERVER_H
#define IPC_SIP_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"


void sip_Ipc_Server_Init(int listen_port);
void sip_Ipc_Server_Destroy();




#endif
