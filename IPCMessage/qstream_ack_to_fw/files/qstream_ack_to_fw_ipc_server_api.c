#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"
#include <stdbool.h>


#define QSTREAM_CHECK_VIDEO_RESOURCE_FROM_FW_ACK	0
#define QSTREAM_ADD_SMART_PHONE_ACK	1


int qstream_ack_to_fw_COMMAND_HANDLER(int command_type, void* parameters);


IpcSocket *g_qstream_ack_to_fw_server;


void qstream_ack_to_fw_Ipc_Server_Init(int listen_port)
{
	g_qstream_ack_to_fw_server = Ipc_Server_Init(listen_port, qstream_ack_to_fw_COMMAND_HANDLER);
}


void qstream_ack_to_fw_Ipc_Server_Destroy()
{
	Ipc_Server_Destroy(g_qstream_ack_to_fw_server);
}


struct qstream_check_video_resource_from_fw_ack_PARAMETERS {
	int result;
};


void qstream_check_video_resource_from_fw_ack_EXECUTE(struct qstream_check_video_resource_from_fw_ack_PARAMETERS *parameters)
{
	embeddedvc_qstream_check_video_resource_from_fw_ack(parameters->result);

}


struct qstream_add_smart_phone_ack_PARAMETERS {
	int local_port;
};


void qstream_add_smart_phone_ack_EXECUTE(struct qstream_add_smart_phone_ack_PARAMETERS *parameters)
{
	embeddedvc_qstream_add_smart_phone_ack(parameters->local_port);

}


int qstream_ack_to_fw_COMMAND_HANDLER(int command_type, void* parameters)
{
	switch (command_type) {
		case QSTREAM_CHECK_VIDEO_RESOURCE_FROM_FW_ACK:
			qstream_check_video_resource_from_fw_ack_EXECUTE((struct qstream_check_video_resource_from_fw_ack_PARAMETERS *)parameters);
			break;
		case QSTREAM_ADD_SMART_PHONE_ACK:
			qstream_add_smart_phone_ack_EXECUTE((struct qstream_add_smart_phone_ack_PARAMETERS *)parameters);
			break;
		default:
			return -1;
			break;
	}

	return 0;
}
