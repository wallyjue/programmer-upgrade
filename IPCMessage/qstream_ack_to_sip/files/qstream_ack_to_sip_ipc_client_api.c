#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"


#define QSTREAM_CHECK_VIDEO_RESOURCE_FROM_SIP_ACK	0


IpcSocket *g_qstream_ack_to_sip_client;


void qstream_ack_to_sip_Ipc_Client_Init(int listen_port)
{
	g_qstream_ack_to_sip_client = Ipc_Client_Init(listen_port);
}


void qstream_ack_to_sip_Ipc_Client_Destroy()
{
	Ipc_Client_Destroy(g_qstream_ack_to_sip_client);
}


struct qstream_check_video_resource_from_sip_ack_PARAMETERS {
	int result;
};


void qstream_check_video_resource_from_sip_ack(int result)
{
	struct qstream_check_video_resource_from_sip_ack_PARAMETERS p;
	int i;

	p.result = result;

	Ipc_Send(g_qstream_ack_to_sip_client, QSTREAM_CHECK_VIDEO_RESOURCE_FROM_SIP_ACK, (void*)&p, sizeof(struct qstream_check_video_resource_from_sip_ack_PARAMETERS));

}


