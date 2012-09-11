#ifndef IPC_QSTREAM_ACK_TO_FW_CLIENT_H
#define IPC_QSTREAM_ACK_TO_FW_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"




void qstream_ack_to_fw_Ipc_Client_Init(int listen_port);
void qstream_ack_to_fw_Ipc_Client_Destroy();


void qstream_check_video_resource_from_fw_ack(int result);
void qstream_add_smart_phone_ack(int local_port);


#endif