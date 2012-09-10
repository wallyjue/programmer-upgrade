#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"


#define FW_INCOMING_CALL	0
#define FW_OUTGOING_IDENTIFY	1
#define FW_OUTBOUND_TIMEOUT	2
#define FW_INBOUND_ANSWER	3
#define FW_INBOUND_TIMEOUT	4
#define FW_INBOUND_TERMINATE_CALL	5
#define FW_INBOUND_HOLD_CALL	6
#define FW_INBOUND_RESUME_CALL	7
#define FW_OUTBOUND_HOLD_CALL_CANCEL	8
#define FW_INBOUND_MUTE	9
#define FW_INBOUND_REQUEST_SWITCH	10
#define FW_INBOUND_CONFIRM_SWITCH	11
#define FW_OUTBOUND_REQUEST_SWITCH_CANCEL	12
#define FW_INBOUND_REQUEST_SWITCH_CANCEL	13
#define FW_CONFERENCE_INCOMING_CALL	14
#define FW_INBOUND_CONFERENCE_RESUME	15
#define FW_CONFERENCE_NOTIFY	16
#define FW_EARLY_DTMF	17
#define FW_SET_MESSAGE	18
#define FW_REGISTER	19
#define FW_REGISTER_TIMEOUT	20
#define FW_FIRST_INCOMING_VIDEO_FRAME	21
#define FW_SET_FRAMEBUFFER	22
#define FW_SET_REMOTE_VIEW_RESOLUTION	23
#define FW_REMOTE_TRANSACTION_BEGIN	24
#define FW_REMOTE_TRANSACTION_END	25
#define FW_SET_LOCAL_VIEW_RESOLUTION	26
#define FW_LOCAL_VIEW_BEGIN	27
#define FW_LOCAL_VIEW_END	28
#define FW_VISUAL_INDICATOR	29
#define FW_REMOTE_VIDEO_TERMINATE_ALERT	30
#define FW_PLAY_RINGBACKTONE	31
#define CM_ACCEPT_CALL	32
#define CM_HOLD_CALL	33
#define CM_RESUME_CALL	34
#define CM_SWAP_CALL	35
#define FW_RECEIVE_TEST_KEY	36
#define FW_STB_RES_CB	37
#define FW_NETWORK_DETECTOR_CB	38
#define FW_NOTIFY_UPDATE_CONFIG	39
#define FW_SET_PRODUCT	40
#define FW_EVENT_EXCEPTION_HANDLE	41
#define FW_OUTGOING_TRANSFER	42
#define FW_INCOMING_TRANSFER	43
#define FW_FORWARD_CALL	44


IpcSocket *g_framework_client;


void framework_Ipc_Client_Init(int listen_port)
{
	g_framework_client = Ipc_Client_Init(listen_port);
}


void framework_Ipc_Client_Destroy()
{
	Ipc_Client_Destroy(g_framework_client);
}


struct fw_incoming_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_incoming_call(char* user_name, char* phone_number, unsigned int mode, int* result)
{
	struct fw_incoming_call_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_framework_client, FW_INCOMING_CALL, (void*)&p, sizeof(struct fw_incoming_call_PARAMETERS));

}


struct fw_outgoing_identify_PARAMETERS {
	char phone_number[128];
	char new_name[128];
	char new_number[128];
	int* result;
};


void fw_outgoing_identify(char* phone_number, char* new_name, char* new_number, int* result)
{
	struct fw_outgoing_identify_PARAMETERS p;
	int i;

	strncpy(p.phone_number, phone_number, 128);

	strncpy(p.new_name, new_name, 128);

	strncpy(p.new_number, new_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, FW_OUTGOING_IDENTIFY, (void*)&p, sizeof(struct fw_outgoing_identify_PARAMETERS));

}


struct fw_outbound_timeout_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_outbound_timeout(char* user_name, char* phone_number, int* result)
{
	struct fw_outbound_timeout_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, FW_OUTBOUND_TIMEOUT, (void*)&p, sizeof(struct fw_outbound_timeout_PARAMETERS));

}


struct fw_inbound_answer_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_inbound_answer(char* user_name, char* phone_number, unsigned int mode, int* result)
{
	struct fw_inbound_answer_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_framework_client, FW_INBOUND_ANSWER, (void*)&p, sizeof(struct fw_inbound_answer_PARAMETERS));

}


struct fw_inbound_timeout_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_inbound_timeout(char* user_name, char* phone_number, int* result)
{
	struct fw_inbound_timeout_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, FW_INBOUND_TIMEOUT, (void*)&p, sizeof(struct fw_inbound_timeout_PARAMETERS));

}


struct fw_inbound_terminate_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_inbound_terminate_call(char* user_name, char* phone_number, int* result)
{
	struct fw_inbound_terminate_call_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, FW_INBOUND_TERMINATE_CALL, (void*)&p, sizeof(struct fw_inbound_terminate_call_PARAMETERS));

}


struct fw_inbound_hold_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_inbound_hold_call(char* user_name, char* phone_number, int* result)
{
	struct fw_inbound_hold_call_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, FW_INBOUND_HOLD_CALL, (void*)&p, sizeof(struct fw_inbound_hold_call_PARAMETERS));

}


struct fw_inbound_resume_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_inbound_resume_call(char* user_name, char* phone_number, int* result)
{
	struct fw_inbound_resume_call_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, FW_INBOUND_RESUME_CALL, (void*)&p, sizeof(struct fw_inbound_resume_call_PARAMETERS));

}


struct fw_outbound_hold_call_cancel_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_outbound_hold_call_cancel(char* user_name, char* phone_number, int* result)
{
	struct fw_outbound_hold_call_cancel_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, FW_OUTBOUND_HOLD_CALL_CANCEL, (void*)&p, sizeof(struct fw_outbound_hold_call_cancel_PARAMETERS));

}


struct fw_inbound_mute_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int isMute;
	int* result;
};


void fw_inbound_mute(char* user_name, char* phone_number, int isMute, int* result)
{
	struct fw_inbound_mute_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.isMute = isMute;

	p.result = result;

	Ipc_Send(g_framework_client, FW_INBOUND_MUTE, (void*)&p, sizeof(struct fw_inbound_mute_PARAMETERS));

}


struct fw_inbound_request_switch_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_inbound_request_switch(char* user_name, char* phone_number, unsigned int mode, int* result)
{
	struct fw_inbound_request_switch_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_framework_client, FW_INBOUND_REQUEST_SWITCH, (void*)&p, sizeof(struct fw_inbound_request_switch_PARAMETERS));

}


struct fw_inbound_confirm_switch_PARAMETERS {
	unsigned int accept;
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_inbound_confirm_switch(unsigned int accept, char* user_name, char* phone_number, unsigned int mode, int* result)
{
	struct fw_inbound_confirm_switch_PARAMETERS p;
	int i;

	p.accept = accept;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_framework_client, FW_INBOUND_CONFIRM_SWITCH, (void*)&p, sizeof(struct fw_inbound_confirm_switch_PARAMETERS));

}


struct fw_outbound_request_switch_cancel_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_outbound_request_switch_cancel(char* user_name, char* phone_number, unsigned int mode, int* result)
{
	struct fw_outbound_request_switch_cancel_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_framework_client, FW_OUTBOUND_REQUEST_SWITCH_CANCEL, (void*)&p, sizeof(struct fw_outbound_request_switch_cancel_PARAMETERS));

}


struct fw_inbound_request_switch_cancel_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_inbound_request_switch_cancel(char* user_name, char* phone_number, unsigned int mode, int* result)
{
	struct fw_inbound_request_switch_cancel_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_framework_client, FW_INBOUND_REQUEST_SWITCH_CANCEL, (void*)&p, sizeof(struct fw_inbound_request_switch_cancel_PARAMETERS));

}


struct fw_conference_incoming_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_conference_incoming_call(char* user_name, char* phone_number, unsigned int mode, int* result)
{
	struct fw_conference_incoming_call_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_framework_client, FW_CONFERENCE_INCOMING_CALL, (void*)&p, sizeof(struct fw_conference_incoming_call_PARAMETERS));

}


struct fw_inbound_conference_resume_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_inbound_conference_resume(char* user_name, char* phone_number, int* result)
{
	struct fw_inbound_conference_resume_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, FW_INBOUND_CONFERENCE_RESUME, (void*)&p, sizeof(struct fw_inbound_conference_resume_PARAMETERS));

}


struct fw_conference_notify_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int number_of_participant;
	int* result;
};


void fw_conference_notify(char* user_name, char* phone_number, unsigned int mode, int number_of_participant, int* result)
{
	struct fw_conference_notify_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.mode = mode;

	p.number_of_participant = number_of_participant;

	p.result = result;

	Ipc_Send(g_framework_client, FW_CONFERENCE_NOTIFY, (void*)&p, sizeof(struct fw_conference_notify_PARAMETERS));

}


struct fw_early_dtmf_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_early_dtmf(char* user_name, char* phone_number, int* result)
{
	struct fw_early_dtmf_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, FW_EARLY_DTMF, (void*)&p, sizeof(struct fw_early_dtmf_PARAMETERS));

}


struct fw_set_message_PARAMETERS {
	unsigned int message_type;
	unsigned int count;
	int* result;
};


void fw_set_message(unsigned int message_type, unsigned int count, int* result)
{
	struct fw_set_message_PARAMETERS p;
	int i;

	p.message_type = message_type;

	p.count = count;

	p.result = result;

	Ipc_Send(g_framework_client, FW_SET_MESSAGE, (void*)&p, sizeof(struct fw_set_message_PARAMETERS));

}


struct fw_register_PARAMETERS {
	int isRegister;
	int* result;
};


void fw_register(int isRegister, int* result)
{
	struct fw_register_PARAMETERS p;
	int i;

	p.isRegister = isRegister;

	p.result = result;

	Ipc_Send(g_framework_client, FW_REGISTER, (void*)&p, sizeof(struct fw_register_PARAMETERS));

}


struct fw_register_timeout_PARAMETERS {
	int* result;
};


void fw_register_timeout(int* result)
{
	struct fw_register_timeout_PARAMETERS p;
	int i;

	p.result = result;

	Ipc_Send(g_framework_client, FW_REGISTER_TIMEOUT, (void*)&p, sizeof(struct fw_register_timeout_PARAMETERS));

}


struct fw_first_incoming_video_frame_PARAMETERS {
	char phone_number[128];
	int* result;
};


void fw_first_incoming_video_frame(char* phone_number, int* result)
{
	struct fw_first_incoming_video_frame_PARAMETERS p;
	int i;

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, FW_FIRST_INCOMING_VIDEO_FRAME, (void*)&p, sizeof(struct fw_first_incoming_video_frame_PARAMETERS));

}


struct fw_set_framebuffer_PARAMETERS {
	char phone_number[128];
	int fb;
	int* result;
};


void fw_set_framebuffer(char* phone_number, int fb, int* result)
{
	struct fw_set_framebuffer_PARAMETERS p;
	int i;

	strncpy(p.phone_number, phone_number, 128);

	p.fb = fb;

	p.result = result;

	Ipc_Send(g_framework_client, FW_SET_FRAMEBUFFER, (void*)&p, sizeof(struct fw_set_framebuffer_PARAMETERS));

}


struct fw_set_remote_view_resolution_PARAMETERS {
	char phone_number[128];
	int width;
	int height;
	int* result;
};


void fw_set_remote_view_resolution(char* phone_number, int width, int height, int* result)
{
	struct fw_set_remote_view_resolution_PARAMETERS p;
	int i;

	strncpy(p.phone_number, phone_number, 128);

	p.width = width;

	p.height = height;

	p.result = result;

	Ipc_Send(g_framework_client, FW_SET_REMOTE_VIEW_RESOLUTION, (void*)&p, sizeof(struct fw_set_remote_view_resolution_PARAMETERS));

}


struct fw_remote_transaction_begin_PARAMETERS {
	char phone_number[128];
	int* result;
};


void fw_remote_transaction_begin(char* phone_number, int* result)
{
	struct fw_remote_transaction_begin_PARAMETERS p;
	int i;

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, FW_REMOTE_TRANSACTION_BEGIN, (void*)&p, sizeof(struct fw_remote_transaction_begin_PARAMETERS));

}


struct fw_remote_transaction_end_PARAMETERS {
	char phone_number[128];
	int* result;
};


void fw_remote_transaction_end(char* phone_number, int* result)
{
	struct fw_remote_transaction_end_PARAMETERS p;
	int i;

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, FW_REMOTE_TRANSACTION_END, (void*)&p, sizeof(struct fw_remote_transaction_end_PARAMETERS));

}


struct fw_set_local_view_resolution_PARAMETERS {
	int width;
	int height;
	int* result;
};


void fw_set_local_view_resolution(int width, int height, int* result)
{
	struct fw_set_local_view_resolution_PARAMETERS p;
	int i;

	p.width = width;

	p.height = height;

	p.result = result;

	Ipc_Send(g_framework_client, FW_SET_LOCAL_VIEW_RESOLUTION, (void*)&p, sizeof(struct fw_set_local_view_resolution_PARAMETERS));

}


struct fw_local_view_begin_PARAMETERS {
	int* result;
};


void fw_local_view_begin(int* result)
{
	struct fw_local_view_begin_PARAMETERS p;
	int i;

	p.result = result;

	Ipc_Send(g_framework_client, FW_LOCAL_VIEW_BEGIN, (void*)&p, sizeof(struct fw_local_view_begin_PARAMETERS));

}


struct fw_local_view_end_PARAMETERS {
	int* result;
};


void fw_local_view_end(int* result)
{
	struct fw_local_view_end_PARAMETERS p;
	int i;

	p.result = result;

	Ipc_Send(g_framework_client, FW_LOCAL_VIEW_END, (void*)&p, sizeof(struct fw_local_view_end_PARAMETERS));

}


struct fw_visual_indicator_PARAMETERS {
	int level;
	int* result;
};


void fw_visual_indicator(int level, int* result)
{
	struct fw_visual_indicator_PARAMETERS p;
	int i;

	p.level = level;

	p.result = result;

	Ipc_Send(g_framework_client, FW_VISUAL_INDICATOR, (void*)&p, sizeof(struct fw_visual_indicator_PARAMETERS));

}


struct fw_remote_video_terminate_alert_PARAMETERS {
	int* result;
};


void fw_remote_video_terminate_alert(int* result)
{
	struct fw_remote_video_terminate_alert_PARAMETERS p;
	int i;

	p.result = result;

	Ipc_Send(g_framework_client, FW_REMOTE_VIDEO_TERMINATE_ALERT, (void*)&p, sizeof(struct fw_remote_video_terminate_alert_PARAMETERS));

}


struct fw_play_ringbacktone_PARAMETERS {
	int ring;
	int* result;
};


void fw_play_ringbacktone(int ring, int* result)
{
	struct fw_play_ringbacktone_PARAMETERS p;
	int i;

	p.ring = ring;

	p.result = result;

	Ipc_Send(g_framework_client, FW_PLAY_RINGBACKTONE, (void*)&p, sizeof(struct fw_play_ringbacktone_PARAMETERS));

}


struct cm_accept_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void cm_accept_call(char* user_name, char* phone_number, int* result)
{
	struct cm_accept_call_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, CM_ACCEPT_CALL, (void*)&p, sizeof(struct cm_accept_call_PARAMETERS));

}


struct cm_hold_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void cm_hold_call(char* user_name, char* phone_number, int* result)
{
	struct cm_hold_call_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, CM_HOLD_CALL, (void*)&p, sizeof(struct cm_hold_call_PARAMETERS));

}


struct cm_resume_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void cm_resume_call(char* user_name, char* phone_number, int* result)
{
	struct cm_resume_call_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, CM_RESUME_CALL, (void*)&p, sizeof(struct cm_resume_call_PARAMETERS));

}


struct cm_swap_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void cm_swap_call(char* user_name, char* phone_number, int* result)
{
	struct cm_swap_call_PARAMETERS p;
	int i;

	strncpy(p.user_name, user_name, 128);

	strncpy(p.phone_number, phone_number, 128);

	p.result = result;

	Ipc_Send(g_framework_client, CM_SWAP_CALL, (void*)&p, sizeof(struct cm_swap_call_PARAMETERS));

}


struct fw_receive_test_key_PARAMETERS {
	int key_code;
	int* result;
};


void fw_receive_test_key(int key_code, int* result)
{
	struct fw_receive_test_key_PARAMETERS p;
	int i;

	p.key_code = key_code;

	p.result = result;

	Ipc_Send(g_framework_client, FW_RECEIVE_TEST_KEY, (void*)&p, sizeof(struct fw_receive_test_key_PARAMETERS));

}


struct fw_stb_res_cb_PARAMETERS {
	int width;
	int height;
	int* result;
};


void fw_stb_res_cb(int width, int height, int* result)
{
	struct fw_stb_res_cb_PARAMETERS p;
	int i;

	p.width = width;

	p.height = height;

	p.result = result;

	Ipc_Send(g_framework_client, FW_STB_RES_CB, (void*)&p, sizeof(struct fw_stb_res_cb_PARAMETERS));

}


struct fw_network_detector_cb_PARAMETERS {
	char interface[128];
	int network_status;
	int ip_changed;
	int* result;
};


void fw_network_detector_cb(char* interface, int network_status, int ip_changed, int* result)
{
	struct fw_network_detector_cb_PARAMETERS p;
	int i;

	strncpy(p.interface, interface, 128);

	p.network_status = network_status;

	p.ip_changed = ip_changed;

	p.result = result;

	Ipc_Send(g_framework_client, FW_NETWORK_DETECTOR_CB, (void*)&p, sizeof(struct fw_network_detector_cb_PARAMETERS));

}


struct fw_notify_update_config_PARAMETERS {
	int notify;
	int* result;
};


void fw_notify_update_config(int notify, int* result)
{
	struct fw_notify_update_config_PARAMETERS p;
	int i;

	p.notify = notify;

	p.result = result;

	Ipc_Send(g_framework_client, FW_NOTIFY_UPDATE_CONFIG, (void*)&p, sizeof(struct fw_notify_update_config_PARAMETERS));

}


struct fw_set_product_PARAMETERS {
	char phone_number[128];
	int product_type;
	int* result;
};


void fw_set_product(char* phone_number, int product_type, int* result)
{
	struct fw_set_product_PARAMETERS p;
	int i;

	strncpy(p.phone_number, phone_number, 128);

	p.product_type = product_type;

	p.result = result;

	Ipc_Send(g_framework_client, FW_SET_PRODUCT, (void*)&p, sizeof(struct fw_set_product_PARAMETERS));

}


struct fw_event_exception_handle_PARAMETERS {
	int component_type;
	int error_code;
	int action;
	int* result;
};


void fw_event_exception_handle(int component_type, int error_code, int action, int* result)
{
	struct fw_event_exception_handle_PARAMETERS p;
	int i;

	p.component_type = component_type;

	p.error_code = error_code;

	p.action = action;

	p.result = result;

	Ipc_Send(g_framework_client, FW_EVENT_EXCEPTION_HANDLE, (void*)&p, sizeof(struct fw_event_exception_handle_PARAMETERS));

}


struct fw_outgoing_transfer_PARAMETERS {
	char phone_number[128];
	char new_name[128];
	char new_number[128];
	unsigned int mode;
	int* result;
};


void fw_outgoing_transfer(char* phone_number, char* new_name, char* new_number, unsigned int mode, int* result)
{
	struct fw_outgoing_transfer_PARAMETERS p;
	int i;

	strncpy(p.phone_number, phone_number, 128);

	strncpy(p.new_name, new_name, 128);

	strncpy(p.new_number, new_number, 128);

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_framework_client, FW_OUTGOING_TRANSFER, (void*)&p, sizeof(struct fw_outgoing_transfer_PARAMETERS));

}


struct fw_incoming_transfer_PARAMETERS {
	char phone_number[128];
	char new_name[128];
	char new_number[128];
	unsigned int mode;
	int* result;
};


void fw_incoming_transfer(char* phone_number, char* new_name, char* new_number, unsigned int mode, int* result)
{
	struct fw_incoming_transfer_PARAMETERS p;
	int i;

	strncpy(p.phone_number, phone_number, 128);

	strncpy(p.new_name, new_name, 128);

	strncpy(p.new_number, new_number, 128);

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_framework_client, FW_INCOMING_TRANSFER, (void*)&p, sizeof(struct fw_incoming_transfer_PARAMETERS));

}


struct fw_forward_call_PARAMETERS {
	char phone_number[128];
	char new_name[128];
	char new_number[128];
	unsigned int mode;
	int* result;
};


void fw_forward_call(char* phone_number, char* new_name, char* new_number, unsigned int mode, int* result)
{
	struct fw_forward_call_PARAMETERS p;
	int i;

	strncpy(p.phone_number, phone_number, 128);

	strncpy(p.new_name, new_name, 128);

	strncpy(p.new_number, new_number, 128);

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_framework_client, FW_FORWARD_CALL, (void*)&p, sizeof(struct fw_forward_call_PARAMETERS));

}


