#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"


#define QSTREAM_CHECK_VIDEO_RESOURCE_FROM_FW_ACK	0
#define QSTREAM_ADD_SMART_PHONE_ACK	1


IpcSocket *g_qstream_ack_to_fw_client;


void qstream_ack_to_fw_Ipc_Client_Init(int listen_port)
{
	g_qstream_ack_to_fw_client = Ipc_Client_Init(listen_port);
}


void qstream_ack_to_fw_Ipc_Client_Destroy()
{
	Ipc_Client_Destroy(g_qstream_ack_to_fw_client);
}


struct qstream_check_video_resource_from_fw_ack_PARAMETERS {
	int result;
};


void qstream_check_video_resource_from_fw_ack(int result)
{
	struct qstream_check_video_resource_from_fw_ack_PARAMETERS p;
	int i;

	p.result = result;

	Ipc_Send(g_qstream_ack_to_fw_client, QSTREAM_CHECK_VIDEO_RESOURCE_FROM_FW_ACK, (void*)&p, sizeof(struct qstream_check_video_resource_from_fw_ack_PARAMETERS));

}


struct qstream_add_smart_phone_ack_PARAMETERS {
	int local_port;
};


void qstream_add_smart_phone_ack(int local_port)
{
	struct qstream_add_smart_phone_ack_PARAMETERS p;
	int i;

	p.local_port = local_port;

	Ipc_Send(g_qstream_ack_to_fw_client, QSTREAM_ADD_SMART_PHONE_ACK, (void*)&p, sizeof(struct qstream_add_smart_phone_ack_PARAMETERS));

}


