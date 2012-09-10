#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"
#include <stdbool.h>


#define QSTREAM_CHECK_VIDEO_RESOURCE_FROM_SIP_ACK	0


int qstream_ack_to_sip_COMMAND_HANDLER(int command_type, void* parameters);


IpcSocket *g_qstream_ack_to_sip_server;


void qstream_ack_to_sip_Ipc_Server_Init(int listen_port)
{
	g_qstream_ack_to_sip_server = Ipc_Server_Init(listen_port, qstream_ack_to_sip_COMMAND_HANDLER);
}


void qstream_ack_to_sip_Ipc_Server_Destroy()
{
	Ipc_Server_Destroy(g_qstream_ack_to_sip_server);
}


struct qstream_check_video_resource_from_sip_ack_PARAMETERS {
	int result;
};


void qstream_check_video_resource_from_sip_ack_EXECUTE(struct qstream_check_video_resource_from_sip_ack_PARAMETERS *parameters)
{
	embeddedvc_qstream_check_video_resource_from_sip_ack(parameters->result);

}


int qstream_ack_to_sip_COMMAND_HANDLER(int command_type, void* parameters)
{
	switch (command_type) {
		case QSTREAM_CHECK_VIDEO_RESOURCE_FROM_SIP_ACK:
			qstream_check_video_resource_from_sip_ack_EXECUTE((struct qstream_check_video_resource_from_sip_ack_PARAMETERS *)parameters);
			break;
		default:
			return -1;
			break;
	}

	return 0;
}
