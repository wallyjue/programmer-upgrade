#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"
#include <stdbool.h>


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


int framework_COMMAND_HANDLER(int command_type, void* parameters);


IpcSocket *g_framework_server;


void framework_Ipc_Server_Init(int listen_port)
{
	g_framework_server = Ipc_Server_Init(listen_port, framework_COMMAND_HANDLER);
}


void framework_Ipc_Server_Destroy()
{
	Ipc_Server_Destroy(g_framework_server);
}


struct fw_incoming_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_incoming_call_EXECUTE(struct fw_incoming_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_incoming_call(parameters->user_name, parameters->phone_number, parameters->mode, parameters->result);

	free(parameters->result);
}


struct fw_outgoing_identify_PARAMETERS {
	char phone_number[128];
	char new_name[128];
	char new_number[128];
	int* result;
};


void fw_outgoing_identify_EXECUTE(struct fw_outgoing_identify_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_outgoing_identify(parameters->phone_number, parameters->new_name, parameters->new_number, parameters->result);

	free(parameters->result);
}


struct fw_outbound_timeout_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_outbound_timeout_EXECUTE(struct fw_outbound_timeout_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_outbound_timeout(parameters->user_name, parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct fw_inbound_answer_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_inbound_answer_EXECUTE(struct fw_inbound_answer_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_inbound_answer(parameters->user_name, parameters->phone_number, parameters->mode, parameters->result);

	free(parameters->result);
}


struct fw_inbound_timeout_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_inbound_timeout_EXECUTE(struct fw_inbound_timeout_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_inbound_timeout(parameters->user_name, parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct fw_inbound_terminate_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_inbound_terminate_call_EXECUTE(struct fw_inbound_terminate_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_inbound_terminate_call(parameters->user_name, parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct fw_inbound_hold_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_inbound_hold_call_EXECUTE(struct fw_inbound_hold_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_inbound_hold_call(parameters->user_name, parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct fw_inbound_resume_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_inbound_resume_call_EXECUTE(struct fw_inbound_resume_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_inbound_resume_call(parameters->user_name, parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct fw_outbound_hold_call_cancel_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_outbound_hold_call_cancel_EXECUTE(struct fw_outbound_hold_call_cancel_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_outbound_hold_call_cancel(parameters->user_name, parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct fw_inbound_mute_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int isMute;
	int* result;
};


void fw_inbound_mute_EXECUTE(struct fw_inbound_mute_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_inbound_mute(parameters->user_name, parameters->phone_number, parameters->isMute, parameters->result);

	free(parameters->result);
}


struct fw_inbound_request_switch_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_inbound_request_switch_EXECUTE(struct fw_inbound_request_switch_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_inbound_request_switch(parameters->user_name, parameters->phone_number, parameters->mode, parameters->result);

	free(parameters->result);
}


struct fw_inbound_confirm_switch_PARAMETERS {
	unsigned int accept;
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_inbound_confirm_switch_EXECUTE(struct fw_inbound_confirm_switch_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_inbound_confirm_switch(parameters->accept, parameters->user_name, parameters->phone_number, parameters->mode, parameters->result);

	free(parameters->result);
}


struct fw_outbound_request_switch_cancel_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_outbound_request_switch_cancel_EXECUTE(struct fw_outbound_request_switch_cancel_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_outbound_request_switch_cancel(parameters->user_name, parameters->phone_number, parameters->mode, parameters->result);

	free(parameters->result);
}


struct fw_inbound_request_switch_cancel_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_inbound_request_switch_cancel_EXECUTE(struct fw_inbound_request_switch_cancel_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_inbound_request_switch_cancel(parameters->user_name, parameters->phone_number, parameters->mode, parameters->result);

	free(parameters->result);
}


struct fw_conference_incoming_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int* result;
};


void fw_conference_incoming_call_EXECUTE(struct fw_conference_incoming_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_conference_incoming_call(parameters->user_name, parameters->phone_number, parameters->mode, parameters->result);

	free(parameters->result);
}


struct fw_inbound_conference_resume_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_inbound_conference_resume_EXECUTE(struct fw_inbound_conference_resume_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_inbound_conference_resume(parameters->user_name, parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct fw_conference_notify_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	unsigned int mode;
	int number_of_participant;
	int* result;
};


void fw_conference_notify_EXECUTE(struct fw_conference_notify_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_conference_notify(parameters->user_name, parameters->phone_number, parameters->mode, parameters->number_of_participant, parameters->result);

	free(parameters->result);
}


struct fw_early_dtmf_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void fw_early_dtmf_EXECUTE(struct fw_early_dtmf_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_early_dtmf(parameters->user_name, parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct fw_set_message_PARAMETERS {
	unsigned int message_type;
	unsigned int count;
	int* result;
};


void fw_set_message_EXECUTE(struct fw_set_message_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_set_message(parameters->message_type, parameters->count, parameters->result);

	free(parameters->result);
}


struct fw_register_PARAMETERS {
	int isRegister;
	int* result;
};


void fw_register_EXECUTE(struct fw_register_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_register(parameters->isRegister, parameters->result);

	free(parameters->result);
}


struct fw_register_timeout_PARAMETERS {
	int* result;
};


void fw_register_timeout_EXECUTE(struct fw_register_timeout_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_register_timeout(parameters->result);

	free(parameters->result);
}


struct fw_first_incoming_video_frame_PARAMETERS {
	char phone_number[128];
	int* result;
};


void fw_first_incoming_video_frame_EXECUTE(struct fw_first_incoming_video_frame_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_first_incoming_video_frame(parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct fw_set_framebuffer_PARAMETERS {
	char phone_number[128];
	int fb;
	int* result;
};


void fw_set_framebuffer_EXECUTE(struct fw_set_framebuffer_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_set_framebuffer(parameters->phone_number, parameters->fb, parameters->result);

	free(parameters->result);
}


struct fw_set_remote_view_resolution_PARAMETERS {
	char phone_number[128];
	int width;
	int height;
	int* result;
};


void fw_set_remote_view_resolution_EXECUTE(struct fw_set_remote_view_resolution_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_set_remote_view_resolution(parameters->phone_number, parameters->width, parameters->height, parameters->result);

	free(parameters->result);
}


struct fw_remote_transaction_begin_PARAMETERS {
	char phone_number[128];
	int* result;
};


void fw_remote_transaction_begin_EXECUTE(struct fw_remote_transaction_begin_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_remote_transaction_begin(parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct fw_remote_transaction_end_PARAMETERS {
	char phone_number[128];
	int* result;
};


void fw_remote_transaction_end_EXECUTE(struct fw_remote_transaction_end_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_remote_transaction_end(parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct fw_set_local_view_resolution_PARAMETERS {
	int width;
	int height;
	int* result;
};


void fw_set_local_view_resolution_EXECUTE(struct fw_set_local_view_resolution_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_set_local_view_resolution(parameters->width, parameters->height, parameters->result);

	free(parameters->result);
}


struct fw_local_view_begin_PARAMETERS {
	int* result;
};


void fw_local_view_begin_EXECUTE(struct fw_local_view_begin_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_local_view_begin(parameters->result);

	free(parameters->result);
}


struct fw_local_view_end_PARAMETERS {
	int* result;
};


void fw_local_view_end_EXECUTE(struct fw_local_view_end_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_local_view_end(parameters->result);

	free(parameters->result);
}


struct fw_visual_indicator_PARAMETERS {
	int level;
	int* result;
};


void fw_visual_indicator_EXECUTE(struct fw_visual_indicator_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_visual_indicator(parameters->level, parameters->result);

	free(parameters->result);
}


struct fw_remote_video_terminate_alert_PARAMETERS {
	int* result;
};


void fw_remote_video_terminate_alert_EXECUTE(struct fw_remote_video_terminate_alert_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_remote_video_terminate_alert(parameters->result);

	free(parameters->result);
}


struct fw_play_ringbacktone_PARAMETERS {
	int ring;
	int* result;
};


void fw_play_ringbacktone_EXECUTE(struct fw_play_ringbacktone_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_play_ringbacktone(parameters->ring, parameters->result);

	free(parameters->result);
}


struct cm_accept_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void cm_accept_call_EXECUTE(struct cm_accept_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	cm_accept_call(parameters->user_name, parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct cm_hold_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void cm_hold_call_EXECUTE(struct cm_hold_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	cm_hold_call(parameters->user_name, parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct cm_resume_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void cm_resume_call_EXECUTE(struct cm_resume_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	cm_resume_call(parameters->user_name, parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct cm_swap_call_PARAMETERS {
	char user_name[128];
	char phone_number[128];
	int* result;
};


void cm_swap_call_EXECUTE(struct cm_swap_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	cm_swap_call(parameters->user_name, parameters->phone_number, parameters->result);

	free(parameters->result);
}


struct fw_receive_test_key_PARAMETERS {
	int key_code;
	int* result;
};


void fw_receive_test_key_EXECUTE(struct fw_receive_test_key_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_receive_test_key(parameters->key_code, parameters->result);

	free(parameters->result);
}


struct fw_stb_res_cb_PARAMETERS {
	int width;
	int height;
	int* result;
};


void fw_stb_res_cb_EXECUTE(struct fw_stb_res_cb_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_stb_res_cb(parameters->width, parameters->height, parameters->result);

	free(parameters->result);
}


struct fw_network_detector_cb_PARAMETERS {
	char interface[128];
	int network_status;
	int ip_changed;
	int* result;
};


void fw_network_detector_cb_EXECUTE(struct fw_network_detector_cb_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_network_detector_cb(parameters->interface, parameters->network_status, parameters->ip_changed, parameters->result);

	free(parameters->result);
}


struct fw_notify_update_config_PARAMETERS {
	int notify;
	int* result;
};


void fw_notify_update_config_EXECUTE(struct fw_notify_update_config_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_notify_update_config(parameters->notify, parameters->result);

	free(parameters->result);
}


struct fw_set_product_PARAMETERS {
	char phone_number[128];
	int product_type;
	int* result;
};


void fw_set_product_EXECUTE(struct fw_set_product_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_set_product(parameters->phone_number, parameters->product_type, parameters->result);

	free(parameters->result);
}


struct fw_event_exception_handle_PARAMETERS {
	int component_type;
	int error_code;
	int action;
	int* result;
};


void fw_event_exception_handle_EXECUTE(struct fw_event_exception_handle_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_event_exception_handle(parameters->component_type, parameters->error_code, parameters->action, parameters->result);

	free(parameters->result);
}


struct fw_outgoing_transfer_PARAMETERS {
	char phone_number[128];
	char new_name[128];
	char new_number[128];
	unsigned int mode;
	int* result;
};


void fw_outgoing_transfer_EXECUTE(struct fw_outgoing_transfer_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_outgoing_transfer(parameters->phone_number, parameters->new_name, parameters->new_number, parameters->mode, parameters->result);

	free(parameters->result);
}


struct fw_incoming_transfer_PARAMETERS {
	char phone_number[128];
	char new_name[128];
	char new_number[128];
	unsigned int mode;
	int* result;
};


void fw_incoming_transfer_EXECUTE(struct fw_incoming_transfer_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_incoming_transfer(parameters->phone_number, parameters->new_name, parameters->new_number, parameters->mode, parameters->result);

	free(parameters->result);
}


struct fw_forward_call_PARAMETERS {
	char phone_number[128];
	char new_name[128];
	char new_number[128];
	unsigned int mode;
	int* result;
};


void fw_forward_call_EXECUTE(struct fw_forward_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	fw_forward_call(parameters->phone_number, parameters->new_name, parameters->new_number, parameters->mode, parameters->result);

	free(parameters->result);
}


int framework_COMMAND_HANDLER(int command_type, void* parameters)
{
	switch (command_type) {
		case FW_INCOMING_CALL:
			fw_incoming_call_EXECUTE((struct fw_incoming_call_PARAMETERS *)parameters);
			break;
		case FW_OUTGOING_IDENTIFY:
			fw_outgoing_identify_EXECUTE((struct fw_outgoing_identify_PARAMETERS *)parameters);
			break;
		case FW_OUTBOUND_TIMEOUT:
			fw_outbound_timeout_EXECUTE((struct fw_outbound_timeout_PARAMETERS *)parameters);
			break;
		case FW_INBOUND_ANSWER:
			fw_inbound_answer_EXECUTE((struct fw_inbound_answer_PARAMETERS *)parameters);
			break;
		case FW_INBOUND_TIMEOUT:
			fw_inbound_timeout_EXECUTE((struct fw_inbound_timeout_PARAMETERS *)parameters);
			break;
		case FW_INBOUND_TERMINATE_CALL:
			fw_inbound_terminate_call_EXECUTE((struct fw_inbound_terminate_call_PARAMETERS *)parameters);
			break;
		case FW_INBOUND_HOLD_CALL:
			fw_inbound_hold_call_EXECUTE((struct fw_inbound_hold_call_PARAMETERS *)parameters);
			break;
		case FW_INBOUND_RESUME_CALL:
			fw_inbound_resume_call_EXECUTE((struct fw_inbound_resume_call_PARAMETERS *)parameters);
			break;
		case FW_OUTBOUND_HOLD_CALL_CANCEL:
			fw_outbound_hold_call_cancel_EXECUTE((struct fw_outbound_hold_call_cancel_PARAMETERS *)parameters);
			break;
		case FW_INBOUND_MUTE:
			fw_inbound_mute_EXECUTE((struct fw_inbound_mute_PARAMETERS *)parameters);
			break;
		case FW_INBOUND_REQUEST_SWITCH:
			fw_inbound_request_switch_EXECUTE((struct fw_inbound_request_switch_PARAMETERS *)parameters);
			break;
		case FW_INBOUND_CONFIRM_SWITCH:
			fw_inbound_confirm_switch_EXECUTE((struct fw_inbound_confirm_switch_PARAMETERS *)parameters);
			break;
		case FW_OUTBOUND_REQUEST_SWITCH_CANCEL:
			fw_outbound_request_switch_cancel_EXECUTE((struct fw_outbound_request_switch_cancel_PARAMETERS *)parameters);
			break;
		case FW_INBOUND_REQUEST_SWITCH_CANCEL:
			fw_inbound_request_switch_cancel_EXECUTE((struct fw_inbound_request_switch_cancel_PARAMETERS *)parameters);
			break;
		case FW_CONFERENCE_INCOMING_CALL:
			fw_conference_incoming_call_EXECUTE((struct fw_conference_incoming_call_PARAMETERS *)parameters);
			break;
		case FW_INBOUND_CONFERENCE_RESUME:
			fw_inbound_conference_resume_EXECUTE((struct fw_inbound_conference_resume_PARAMETERS *)parameters);
			break;
		case FW_CONFERENCE_NOTIFY:
			fw_conference_notify_EXECUTE((struct fw_conference_notify_PARAMETERS *)parameters);
			break;
		case FW_EARLY_DTMF:
			fw_early_dtmf_EXECUTE((struct fw_early_dtmf_PARAMETERS *)parameters);
			break;
		case FW_SET_MESSAGE:
			fw_set_message_EXECUTE((struct fw_set_message_PARAMETERS *)parameters);
			break;
		case FW_REGISTER:
			fw_register_EXECUTE((struct fw_register_PARAMETERS *)parameters);
			break;
		case FW_REGISTER_TIMEOUT:
			fw_register_timeout_EXECUTE((struct fw_register_timeout_PARAMETERS *)parameters);
			break;
		case FW_FIRST_INCOMING_VIDEO_FRAME:
			fw_first_incoming_video_frame_EXECUTE((struct fw_first_incoming_video_frame_PARAMETERS *)parameters);
			break;
		case FW_SET_FRAMEBUFFER:
			fw_set_framebuffer_EXECUTE((struct fw_set_framebuffer_PARAMETERS *)parameters);
			break;
		case FW_SET_REMOTE_VIEW_RESOLUTION:
			fw_set_remote_view_resolution_EXECUTE((struct fw_set_remote_view_resolution_PARAMETERS *)parameters);
			break;
		case FW_REMOTE_TRANSACTION_BEGIN:
			fw_remote_transaction_begin_EXECUTE((struct fw_remote_transaction_begin_PARAMETERS *)parameters);
			break;
		case FW_REMOTE_TRANSACTION_END:
			fw_remote_transaction_end_EXECUTE((struct fw_remote_transaction_end_PARAMETERS *)parameters);
			break;
		case FW_SET_LOCAL_VIEW_RESOLUTION:
			fw_set_local_view_resolution_EXECUTE((struct fw_set_local_view_resolution_PARAMETERS *)parameters);
			break;
		case FW_LOCAL_VIEW_BEGIN:
			fw_local_view_begin_EXECUTE((struct fw_local_view_begin_PARAMETERS *)parameters);
			break;
		case FW_LOCAL_VIEW_END:
			fw_local_view_end_EXECUTE((struct fw_local_view_end_PARAMETERS *)parameters);
			break;
		case FW_VISUAL_INDICATOR:
			fw_visual_indicator_EXECUTE((struct fw_visual_indicator_PARAMETERS *)parameters);
			break;
		case FW_REMOTE_VIDEO_TERMINATE_ALERT:
			fw_remote_video_terminate_alert_EXECUTE((struct fw_remote_video_terminate_alert_PARAMETERS *)parameters);
			break;
		case FW_PLAY_RINGBACKTONE:
			fw_play_ringbacktone_EXECUTE((struct fw_play_ringbacktone_PARAMETERS *)parameters);
			break;
		case CM_ACCEPT_CALL:
			cm_accept_call_EXECUTE((struct cm_accept_call_PARAMETERS *)parameters);
			break;
		case CM_HOLD_CALL:
			cm_hold_call_EXECUTE((struct cm_hold_call_PARAMETERS *)parameters);
			break;
		case CM_RESUME_CALL:
			cm_resume_call_EXECUTE((struct cm_resume_call_PARAMETERS *)parameters);
			break;
		case CM_SWAP_CALL:
			cm_swap_call_EXECUTE((struct cm_swap_call_PARAMETERS *)parameters);
			break;
		case FW_RECEIVE_TEST_KEY:
			fw_receive_test_key_EXECUTE((struct fw_receive_test_key_PARAMETERS *)parameters);
			break;
		case FW_STB_RES_CB:
			fw_stb_res_cb_EXECUTE((struct fw_stb_res_cb_PARAMETERS *)parameters);
			break;
		case FW_NETWORK_DETECTOR_CB:
			fw_network_detector_cb_EXECUTE((struct fw_network_detector_cb_PARAMETERS *)parameters);
			break;
		case FW_NOTIFY_UPDATE_CONFIG:
			fw_notify_update_config_EXECUTE((struct fw_notify_update_config_PARAMETERS *)parameters);
			break;
		case FW_SET_PRODUCT:
			fw_set_product_EXECUTE((struct fw_set_product_PARAMETERS *)parameters);
			break;
		case FW_EVENT_EXCEPTION_HANDLE:
			fw_event_exception_handle_EXECUTE((struct fw_event_exception_handle_PARAMETERS *)parameters);
			break;
		case FW_OUTGOING_TRANSFER:
			fw_outgoing_transfer_EXECUTE((struct fw_outgoing_transfer_PARAMETERS *)parameters);
			break;
		case FW_INCOMING_TRANSFER:
			fw_incoming_transfer_EXECUTE((struct fw_incoming_transfer_PARAMETERS *)parameters);
			break;
		case FW_FORWARD_CALL:
			fw_forward_call_EXECUTE((struct fw_forward_call_PARAMETERS *)parameters);
			break;
		default:
			return -1;
			break;
	}

	return 0;
}
