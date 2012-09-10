#ifndef IPC_QSTREAM_ACK_TO_FW_SERVER_H
#define IPC_QSTREAM_ACK_TO_FW_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"


void qstream_ack_to_fw_Ipc_Server_Init(int listen_port);
void qstream_ack_to_fw_Ipc_Server_Destroy();




#endif
