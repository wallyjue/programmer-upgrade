#ifndef IPC_FRAMEWORK_SERVER_H
#define IPC_FRAMEWORK_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"


void framework_Ipc_Server_Init(int listen_port);
void framework_Ipc_Server_Destroy();




#endif
