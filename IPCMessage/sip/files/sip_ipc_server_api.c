#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"
#include <stdbool.h>


#define SIP_MAKE_REGISTRATION	0
#define SIP_MAKE_CALL	1
#define SIP_SET_CALL_REJECTION	2
#define SIP_HOLD_CALL	3
#define SIP_RESUME_CALL	4
#define SIP_REQUEST_SWITCH	5
#define SIP_CONFIRM_SWITCH	6
#define SIP_START_CONFERENCE_CALL	7
#define SIP_START_VIDEO_CONFERENCE_CALL	8
#define SIP_MAKE_VIDEO_CONFERENCE_CALL	9
#define SIP_VIDEO_CONFERENCE_HOLD_CALL	10
#define SIP_VIDEO_CONFERENCE_RESUME_CALL	11
#define SIP_TERMINATE_CALL	12
#define SIP_CANCEL_CALL	13
#define SIP_ANSWER_CALL	14
#define SIP_REJECT_CALL	15
#define SIP_SET_DND	16
#define SIP_SET_CALL_FORWARDING	17
#define SIP_SET_CALL_WAITING	18
#define SIP_SWAP_WAITING_CALL	19
#define SIP_UNATTEND_TRANSFER	20
#define SIP_ATTEND_TRANSFER	21
#define SIP_FORWARD_CALL	22
#define SIP_SET_INVITE_PROGRESS	23
#define SIP_GET_SEESION	24
#define SIP_TRANSMIT_DTMF	25
#define SIP_INFO_DTMF	26
#define SIP_GET_MESSAGE	27
#define SIP_REQUEST_IDR	28
#define SIP_RESTART	29
#define SIP_REGISTER	30
#define SIP_SET_AUTOANSWER	31


int sip_COMMAND_HANDLER(int command_type, void* parameters);


IpcSocket *g_sip_server;


void sip_Ipc_Server_Init(int listen_port)
{
	g_sip_server = Ipc_Server_Init(listen_port, sip_COMMAND_HANDLER);
}


void sip_Ipc_Server_Destroy()
{
	Ipc_Server_Destroy(g_sip_server);
}


struct sip_make_registration_PARAMETERS {
	char URI[128];
	char proxy[128];
	char realm[128];
	char sipid[128];
	char name[128];
	char psw[128];
	int* result;
};


void sip_make_registration_EXECUTE(struct sip_make_registration_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_make_registration(parameters->URI, parameters->proxy, parameters->realm, parameters->sipid, parameters->name, parameters->psw, parameters->result);

	free(parameters->result);
}


struct sip_make_call_PARAMETERS {
	unsigned int mode;
	char addr[128];
	int audio_source;
	int* result;
};


void sip_make_call_EXECUTE(struct sip_make_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_make_call(parameters->mode, parameters->addr, parameters->audio_source, parameters->result);

	free(parameters->result);
}


struct sip_set_call_rejection_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_set_call_rejection_EXECUTE(struct sip_set_call_rejection_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_set_call_rejection(parameters->addr, parameters->result);

	free(parameters->result);
}


struct sip_hold_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_hold_call_EXECUTE(struct sip_hold_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_hold_call(parameters->addr, parameters->result);

	free(parameters->result);
}


struct sip_resume_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_resume_call_EXECUTE(struct sip_resume_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_resume_call(parameters->addr, parameters->result);

	free(parameters->result);
}


struct sip_request_switch_PARAMETERS {
	int mode;
	char addr[128];
	int* result;
};


void sip_request_switch_EXECUTE(struct sip_request_switch_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_request_switch(parameters->mode, parameters->addr, parameters->result);

	free(parameters->result);
}


struct sip_confirm_switch_PARAMETERS {
	int accept;
	int mode;
	char addr[128];
	int* result;
};


void sip_confirm_switch_EXECUTE(struct sip_confirm_switch_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_confirm_switch(parameters->accept, parameters->mode, parameters->addr, parameters->result);

	free(parameters->result);
}


struct sip_start_conference_call_PARAMETERS {
	char addr1[128];
	char addr2[128];
	int* result;
};


void sip_start_conference_call_EXECUTE(struct sip_start_conference_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_start_conference_call(parameters->addr1, parameters->addr2, parameters->result);

	free(parameters->result);
}


struct sip_start_video_conference_call_PARAMETERS {
	int* result;
};


void sip_start_video_conference_call_EXECUTE(struct sip_start_video_conference_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_start_video_conference_call(parameters->result);

	free(parameters->result);
}


struct sip_make_video_conference_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_make_video_conference_call_EXECUTE(struct sip_make_video_conference_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_make_video_conference_call(parameters->addr, parameters->result);

	free(parameters->result);
}


struct sip_video_conference_hold_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_video_conference_hold_call_EXECUTE(struct sip_video_conference_hold_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_video_conference_hold_call(parameters->addr, parameters->result);

	free(parameters->result);
}


struct sip_video_conference_resume_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_video_conference_resume_call_EXECUTE(struct sip_video_conference_resume_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_video_conference_resume_call(parameters->addr, parameters->result);

	free(parameters->result);
}


struct sip_terminate_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_terminate_call_EXECUTE(struct sip_terminate_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_terminate_call(parameters->addr, parameters->result);

	free(parameters->result);
}


struct sip_cancel_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_cancel_call_EXECUTE(struct sip_cancel_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_cancel_call(parameters->addr, parameters->result);

	free(parameters->result);
}


struct sip_answer_call_PARAMETERS {
	int mode;
	char addr[128];
	int audio_source;
	int* result;
};


void sip_answer_call_EXECUTE(struct sip_answer_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_answer_call(parameters->mode, parameters->addr, parameters->audio_source, parameters->result);

	free(parameters->result);
}


struct sip_reject_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_reject_call_EXECUTE(struct sip_reject_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_reject_call(parameters->addr, parameters->result);

	free(parameters->result);
}


struct sip_set_dnd_PARAMETERS {
	bool IsDND;
	int* result;
};


void sip_set_dnd_EXECUTE(struct sip_set_dnd_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_set_dnd(parameters->IsDND, parameters->result);

	free(parameters->result);
}


struct sip_set_call_forwarding_PARAMETERS {
	int mode;
	int type;
	char addr[128];
	int* result;
};


void sip_set_call_forwarding_EXECUTE(struct sip_set_call_forwarding_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_set_call_forwarding(parameters->mode, parameters->type, parameters->addr, parameters->result);

	free(parameters->result);
}


struct sip_set_call_waiting_PARAMETERS {
	bool IsWait;
	int* result;
};


void sip_set_call_waiting_EXECUTE(struct sip_set_call_waiting_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_set_call_waiting(parameters->IsWait, parameters->result);

	free(parameters->result);
}


struct sip_swap_waiting_call_PARAMETERS {
	char active_addr[128];
	char hold_addr[128];
	int* result;
};


void sip_swap_waiting_call_EXECUTE(struct sip_swap_waiting_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_swap_waiting_call(parameters->active_addr, parameters->hold_addr, parameters->result);

	free(parameters->result);
}


struct sip_unattend_transfer_PARAMETERS {
	char addr[128];
	char target_addr[128];
	int* result;
};


void sip_unattend_transfer_EXECUTE(struct sip_unattend_transfer_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_unattend_transfer(parameters->addr, parameters->target_addr, parameters->result);

	free(parameters->result);
}


struct sip_attend_transfer_PARAMETERS {
	char addr[128];
	char target_addr[128];
	int* result;
};


void sip_attend_transfer_EXECUTE(struct sip_attend_transfer_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_attend_transfer(parameters->addr, parameters->target_addr, parameters->result);

	free(parameters->result);
}


struct sip_forward_call_PARAMETERS {
	char addr[128];
	char target_addr[128];
	int* result;
};


void sip_forward_call_EXECUTE(struct sip_forward_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_forward_call(parameters->addr, parameters->target_addr, parameters->result);

	free(parameters->result);
}


struct sip_set_invite_progress_PARAMETERS {
	bool inviteProgress;
	int* result;
};


void sip_set_invite_progress_EXECUTE(struct sip_set_invite_progress_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_set_invite_progress(parameters->inviteProgress, parameters->result);

	free(parameters->result);
}


struct sip_get_seesion_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_get_seesion_EXECUTE(struct sip_get_seesion_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_get_seesion(parameters->addr, parameters->result);

	free(parameters->result);
}


struct sip_transmit_dtmf_PARAMETERS {
	char addr[128];
	int event;
	int duration;
	int* result;
};


void sip_transmit_dtmf_EXECUTE(struct sip_transmit_dtmf_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_transmit_dtmf(parameters->addr, parameters->event, parameters->duration, parameters->result);

	free(parameters->result);
}


struct sip_info_dtmf_PARAMETERS {
	char addr[128];
	int event;
	int duration;
	int* result;
};


void sip_info_dtmf_EXECUTE(struct sip_info_dtmf_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_info_dtmf(parameters->addr, parameters->event, parameters->duration, parameters->result);

	free(parameters->result);
}


struct sip_get_message_PARAMETERS {
	unsigned int message_type;
	int* result;
};


void sip_get_message_EXECUTE(struct sip_get_message_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_get_message(parameters->message_type, parameters->result);

	free(parameters->result);
}


struct sip_request_idr_PARAMETERS {
	int session;
	int* result;
};


void sip_request_idr_EXECUTE(struct sip_request_idr_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_request_idr(parameters->session, parameters->result);

	free(parameters->result);
}


struct sip_restart_PARAMETERS {
	int* result;
};


void sip_restart_EXECUTE(struct sip_restart_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_restart(parameters->result);

	free(parameters->result);
}


struct sip_register_PARAMETERS {
	int* result;
};


void sip_register_EXECUTE(struct sip_register_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_register(parameters->result);

	free(parameters->result);
}


struct sip_set_autoanswer_PARAMETERS {
	bool auto_answer;
	int* result;
};


void sip_set_autoanswer_EXECUTE(struct sip_set_autoanswer_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	sip_set_autoanswer(parameters->auto_answer, parameters->result);

	free(parameters->result);
}


int sip_COMMAND_HANDLER(int command_type, void* parameters)
{
	switch (command_type) {
		case SIP_MAKE_REGISTRATION:
			sip_make_registration_EXECUTE((struct sip_make_registration_PARAMETERS *)parameters);
			break;
		case SIP_MAKE_CALL:
			sip_make_call_EXECUTE((struct sip_make_call_PARAMETERS *)parameters);
			break;
		case SIP_SET_CALL_REJECTION:
			sip_set_call_rejection_EXECUTE((struct sip_set_call_rejection_PARAMETERS *)parameters);
			break;
		case SIP_HOLD_CALL:
			sip_hold_call_EXECUTE((struct sip_hold_call_PARAMETERS *)parameters);
			break;
		case SIP_RESUME_CALL:
			sip_resume_call_EXECUTE((struct sip_resume_call_PARAMETERS *)parameters);
			break;
		case SIP_REQUEST_SWITCH:
			sip_request_switch_EXECUTE((struct sip_request_switch_PARAMETERS *)parameters);
			break;
		case SIP_CONFIRM_SWITCH:
			sip_confirm_switch_EXECUTE((struct sip_confirm_switch_PARAMETERS *)parameters);
			break;
		case SIP_START_CONFERENCE_CALL:
			sip_start_conference_call_EXECUTE((struct sip_start_conference_call_PARAMETERS *)parameters);
			break;
		case SIP_START_VIDEO_CONFERENCE_CALL:
			sip_start_video_conference_call_EXECUTE((struct sip_start_video_conference_call_PARAMETERS *)parameters);
			break;
		case SIP_MAKE_VIDEO_CONFERENCE_CALL:
			sip_make_video_conference_call_EXECUTE((struct sip_make_video_conference_call_PARAMETERS *)parameters);
			break;
		case SIP_VIDEO_CONFERENCE_HOLD_CALL:
			sip_video_conference_hold_call_EXECUTE((struct sip_video_conference_hold_call_PARAMETERS *)parameters);
			break;
		case SIP_VIDEO_CONFERENCE_RESUME_CALL:
			sip_video_conference_resume_call_EXECUTE((struct sip_video_conference_resume_call_PARAMETERS *)parameters);
			break;
		case SIP_TERMINATE_CALL:
			sip_terminate_call_EXECUTE((struct sip_terminate_call_PARAMETERS *)parameters);
			break;
		case SIP_CANCEL_CALL:
			sip_cancel_call_EXECUTE((struct sip_cancel_call_PARAMETERS *)parameters);
			break;
		case SIP_ANSWER_CALL:
			sip_answer_call_EXECUTE((struct sip_answer_call_PARAMETERS *)parameters);
			break;
		case SIP_REJECT_CALL:
			sip_reject_call_EXECUTE((struct sip_reject_call_PARAMETERS *)parameters);
			break;
		case SIP_SET_DND:
			sip_set_dnd_EXECUTE((struct sip_set_dnd_PARAMETERS *)parameters);
			break;
		case SIP_SET_CALL_FORWARDING:
			sip_set_call_forwarding_EXECUTE((struct sip_set_call_forwarding_PARAMETERS *)parameters);
			break;
		case SIP_SET_CALL_WAITING:
			sip_set_call_waiting_EXECUTE((struct sip_set_call_waiting_PARAMETERS *)parameters);
			break;
		case SIP_SWAP_WAITING_CALL:
			sip_swap_waiting_call_EXECUTE((struct sip_swap_waiting_call_PARAMETERS *)parameters);
			break;
		case SIP_UNATTEND_TRANSFER:
			sip_unattend_transfer_EXECUTE((struct sip_unattend_transfer_PARAMETERS *)parameters);
			break;
		case SIP_ATTEND_TRANSFER:
			sip_attend_transfer_EXECUTE((struct sip_attend_transfer_PARAMETERS *)parameters);
			break;
		case SIP_FORWARD_CALL:
			sip_forward_call_EXECUTE((struct sip_forward_call_PARAMETERS *)parameters);
			break;
		case SIP_SET_INVITE_PROGRESS:
			sip_set_invite_progress_EXECUTE((struct sip_set_invite_progress_PARAMETERS *)parameters);
			break;
		case SIP_GET_SEESION:
			sip_get_seesion_EXECUTE((struct sip_get_seesion_PARAMETERS *)parameters);
			break;
		case SIP_TRANSMIT_DTMF:
			sip_transmit_dtmf_EXECUTE((struct sip_transmit_dtmf_PARAMETERS *)parameters);
			break;
		case SIP_INFO_DTMF:
			sip_info_dtmf_EXECUTE((struct sip_info_dtmf_PARAMETERS *)parameters);
			break;
		case SIP_GET_MESSAGE:
			sip_get_message_EXECUTE((struct sip_get_message_PARAMETERS *)parameters);
			break;
		case SIP_REQUEST_IDR:
			sip_request_idr_EXECUTE((struct sip_request_idr_PARAMETERS *)parameters);
			break;
		case SIP_RESTART:
			sip_restart_EXECUTE((struct sip_restart_PARAMETERS *)parameters);
			break;
		case SIP_REGISTER:
			sip_register_EXECUTE((struct sip_register_PARAMETERS *)parameters);
			break;
		case SIP_SET_AUTOANSWER:
			sip_set_autoanswer_EXECUTE((struct sip_set_autoanswer_PARAMETERS *)parameters);
			break;
		default:
			return -1;
			break;
	}

	return 0;
}
