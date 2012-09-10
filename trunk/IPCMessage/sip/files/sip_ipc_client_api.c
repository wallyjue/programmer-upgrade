#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"


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


IpcSocket *g_sip_client;


void sip_Ipc_Client_Init(int listen_port)
{
	g_sip_client = Ipc_Client_Init(listen_port);
}


void sip_Ipc_Client_Destroy()
{
	Ipc_Client_Destroy(g_sip_client);
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


void sip_make_registration(char* URI, char* proxy, char* realm, char* sipid, char* name, char* psw, int* result)
{
	struct sip_make_registration_PARAMETERS p;
	int i;

	strncpy(p.URI, URI, 128);

	strncpy(p.proxy, proxy, 128);

	strncpy(p.realm, realm, 128);

	strncpy(p.sipid, sipid, 128);

	strncpy(p.name, name, 128);

	strncpy(p.psw, psw, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_MAKE_REGISTRATION, (void*)&p, sizeof(struct sip_make_registration_PARAMETERS));

}


struct sip_make_call_PARAMETERS {
	unsigned int mode;
	char addr[128];
	int audio_source;
	int* result;
};


void sip_make_call(unsigned int mode, char* addr, int audio_source, int* result)
{
	struct sip_make_call_PARAMETERS p;
	int i;

	p.mode = mode;

	strncpy(p.addr, addr, 128);

	p.audio_source = audio_source;

	p.result = result;

	Ipc_Send(g_sip_client, SIP_MAKE_CALL, (void*)&p, sizeof(struct sip_make_call_PARAMETERS));

}


struct sip_set_call_rejection_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_set_call_rejection(char* addr, int* result)
{
	struct sip_set_call_rejection_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_SET_CALL_REJECTION, (void*)&p, sizeof(struct sip_set_call_rejection_PARAMETERS));

}


struct sip_hold_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_hold_call(char* addr, int* result)
{
	struct sip_hold_call_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_HOLD_CALL, (void*)&p, sizeof(struct sip_hold_call_PARAMETERS));

}


struct sip_resume_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_resume_call(char* addr, int* result)
{
	struct sip_resume_call_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_RESUME_CALL, (void*)&p, sizeof(struct sip_resume_call_PARAMETERS));

}


struct sip_request_switch_PARAMETERS {
	int mode;
	char addr[128];
	int* result;
};


void sip_request_switch(int mode, char* addr, int* result)
{
	struct sip_request_switch_PARAMETERS p;
	int i;

	p.mode = mode;

	strncpy(p.addr, addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_REQUEST_SWITCH, (void*)&p, sizeof(struct sip_request_switch_PARAMETERS));

}


struct sip_confirm_switch_PARAMETERS {
	int accept;
	int mode;
	char addr[128];
	int* result;
};


void sip_confirm_switch(int accept, int mode, char* addr, int* result)
{
	struct sip_confirm_switch_PARAMETERS p;
	int i;

	p.accept = accept;

	p.mode = mode;

	strncpy(p.addr, addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_CONFIRM_SWITCH, (void*)&p, sizeof(struct sip_confirm_switch_PARAMETERS));

}


struct sip_start_conference_call_PARAMETERS {
	char addr1[128];
	char addr2[128];
	int* result;
};


void sip_start_conference_call(char* addr1, char* addr2, int* result)
{
	struct sip_start_conference_call_PARAMETERS p;
	int i;

	strncpy(p.addr1, addr1, 128);

	strncpy(p.addr2, addr2, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_START_CONFERENCE_CALL, (void*)&p, sizeof(struct sip_start_conference_call_PARAMETERS));

}


struct sip_start_video_conference_call_PARAMETERS {
	int* result;
};


void sip_start_video_conference_call(int* result)
{
	struct sip_start_video_conference_call_PARAMETERS p;
	int i;

	p.result = result;

	Ipc_Send(g_sip_client, SIP_START_VIDEO_CONFERENCE_CALL, (void*)&p, sizeof(struct sip_start_video_conference_call_PARAMETERS));

}


struct sip_make_video_conference_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_make_video_conference_call(char* addr, int* result)
{
	struct sip_make_video_conference_call_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_MAKE_VIDEO_CONFERENCE_CALL, (void*)&p, sizeof(struct sip_make_video_conference_call_PARAMETERS));

}


struct sip_video_conference_hold_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_video_conference_hold_call(char* addr, int* result)
{
	struct sip_video_conference_hold_call_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_VIDEO_CONFERENCE_HOLD_CALL, (void*)&p, sizeof(struct sip_video_conference_hold_call_PARAMETERS));

}


struct sip_video_conference_resume_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_video_conference_resume_call(char* addr, int* result)
{
	struct sip_video_conference_resume_call_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_VIDEO_CONFERENCE_RESUME_CALL, (void*)&p, sizeof(struct sip_video_conference_resume_call_PARAMETERS));

}


struct sip_terminate_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_terminate_call(char* addr, int* result)
{
	struct sip_terminate_call_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_TERMINATE_CALL, (void*)&p, sizeof(struct sip_terminate_call_PARAMETERS));

}


struct sip_cancel_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_cancel_call(char* addr, int* result)
{
	struct sip_cancel_call_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_CANCEL_CALL, (void*)&p, sizeof(struct sip_cancel_call_PARAMETERS));

}


struct sip_answer_call_PARAMETERS {
	int mode;
	char addr[128];
	int audio_source;
	int* result;
};


void sip_answer_call(int mode, char* addr, int audio_source, int* result)
{
	struct sip_answer_call_PARAMETERS p;
	int i;

	p.mode = mode;

	strncpy(p.addr, addr, 128);

	p.audio_source = audio_source;

	p.result = result;

	Ipc_Send(g_sip_client, SIP_ANSWER_CALL, (void*)&p, sizeof(struct sip_answer_call_PARAMETERS));

}


struct sip_reject_call_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_reject_call(char* addr, int* result)
{
	struct sip_reject_call_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_REJECT_CALL, (void*)&p, sizeof(struct sip_reject_call_PARAMETERS));

}


struct sip_set_dnd_PARAMETERS {
	bool IsDND;
	int* result;
};


void sip_set_dnd(bool IsDND, int* result)
{
	struct sip_set_dnd_PARAMETERS p;
	int i;

	p.IsDND = IsDND;

	p.result = result;

	Ipc_Send(g_sip_client, SIP_SET_DND, (void*)&p, sizeof(struct sip_set_dnd_PARAMETERS));

}


struct sip_set_call_forwarding_PARAMETERS {
	int mode;
	int type;
	char addr[128];
	int* result;
};


void sip_set_call_forwarding(int mode, int type, char* addr, int* result)
{
	struct sip_set_call_forwarding_PARAMETERS p;
	int i;

	p.mode = mode;

	p.type = type;

	strncpy(p.addr, addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_SET_CALL_FORWARDING, (void*)&p, sizeof(struct sip_set_call_forwarding_PARAMETERS));

}


struct sip_set_call_waiting_PARAMETERS {
	bool IsWait;
	int* result;
};


void sip_set_call_waiting(bool IsWait, int* result)
{
	struct sip_set_call_waiting_PARAMETERS p;
	int i;

	p.IsWait = IsWait;

	p.result = result;

	Ipc_Send(g_sip_client, SIP_SET_CALL_WAITING, (void*)&p, sizeof(struct sip_set_call_waiting_PARAMETERS));

}


struct sip_swap_waiting_call_PARAMETERS {
	char active_addr[128];
	char hold_addr[128];
	int* result;
};


void sip_swap_waiting_call(char* active_addr, char* hold_addr, int* result)
{
	struct sip_swap_waiting_call_PARAMETERS p;
	int i;

	strncpy(p.active_addr, active_addr, 128);

	strncpy(p.hold_addr, hold_addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_SWAP_WAITING_CALL, (void*)&p, sizeof(struct sip_swap_waiting_call_PARAMETERS));

}


struct sip_unattend_transfer_PARAMETERS {
	char addr[128];
	char target_addr[128];
	int* result;
};


void sip_unattend_transfer(char* addr, char* target_addr, int* result)
{
	struct sip_unattend_transfer_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	strncpy(p.target_addr, target_addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_UNATTEND_TRANSFER, (void*)&p, sizeof(struct sip_unattend_transfer_PARAMETERS));

}


struct sip_attend_transfer_PARAMETERS {
	char addr[128];
	char target_addr[128];
	int* result;
};


void sip_attend_transfer(char* addr, char* target_addr, int* result)
{
	struct sip_attend_transfer_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	strncpy(p.target_addr, target_addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_ATTEND_TRANSFER, (void*)&p, sizeof(struct sip_attend_transfer_PARAMETERS));

}


struct sip_forward_call_PARAMETERS {
	char addr[128];
	char target_addr[128];
	int* result;
};


void sip_forward_call(char* addr, char* target_addr, int* result)
{
	struct sip_forward_call_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	strncpy(p.target_addr, target_addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_FORWARD_CALL, (void*)&p, sizeof(struct sip_forward_call_PARAMETERS));

}


struct sip_set_invite_progress_PARAMETERS {
	bool inviteProgress;
	int* result;
};


void sip_set_invite_progress(bool inviteProgress, int* result)
{
	struct sip_set_invite_progress_PARAMETERS p;
	int i;

	p.inviteProgress = inviteProgress;

	p.result = result;

	Ipc_Send(g_sip_client, SIP_SET_INVITE_PROGRESS, (void*)&p, sizeof(struct sip_set_invite_progress_PARAMETERS));

}


struct sip_get_seesion_PARAMETERS {
	char addr[128];
	int* result;
};


void sip_get_seesion(char* addr, int* result)
{
	struct sip_get_seesion_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	p.result = result;

	Ipc_Send(g_sip_client, SIP_GET_SEESION, (void*)&p, sizeof(struct sip_get_seesion_PARAMETERS));

}


struct sip_transmit_dtmf_PARAMETERS {
	char addr[128];
	int event;
	int duration;
	int* result;
};


void sip_transmit_dtmf(char* addr, int event, int duration, int* result)
{
	struct sip_transmit_dtmf_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	p.event = event;

	p.duration = duration;

	p.result = result;

	Ipc_Send(g_sip_client, SIP_TRANSMIT_DTMF, (void*)&p, sizeof(struct sip_transmit_dtmf_PARAMETERS));

}


struct sip_info_dtmf_PARAMETERS {
	char addr[128];
	int event;
	int duration;
	int* result;
};


void sip_info_dtmf(char* addr, int event, int duration, int* result)
{
	struct sip_info_dtmf_PARAMETERS p;
	int i;

	strncpy(p.addr, addr, 128);

	p.event = event;

	p.duration = duration;

	p.result = result;

	Ipc_Send(g_sip_client, SIP_INFO_DTMF, (void*)&p, sizeof(struct sip_info_dtmf_PARAMETERS));

}


struct sip_get_message_PARAMETERS {
	unsigned int message_type;
	int* result;
};


void sip_get_message(unsigned int message_type, int* result)
{
	struct sip_get_message_PARAMETERS p;
	int i;

	p.message_type = message_type;

	p.result = result;

	Ipc_Send(g_sip_client, SIP_GET_MESSAGE, (void*)&p, sizeof(struct sip_get_message_PARAMETERS));

}


struct sip_request_idr_PARAMETERS {
	int session;
	int* result;
};


void sip_request_idr(int session, int* result)
{
	struct sip_request_idr_PARAMETERS p;
	int i;

	p.session = session;

	p.result = result;

	Ipc_Send(g_sip_client, SIP_REQUEST_IDR, (void*)&p, sizeof(struct sip_request_idr_PARAMETERS));

}


struct sip_restart_PARAMETERS {
	int* result;
};


void sip_restart(int* result)
{
	struct sip_restart_PARAMETERS p;
	int i;

	p.result = result;

	Ipc_Send(g_sip_client, SIP_RESTART, (void*)&p, sizeof(struct sip_restart_PARAMETERS));

}


struct sip_register_PARAMETERS {
	int* result;
};


void sip_register(int* result)
{
	struct sip_register_PARAMETERS p;
	int i;

	p.result = result;

	Ipc_Send(g_sip_client, SIP_REGISTER, (void*)&p, sizeof(struct sip_register_PARAMETERS));

}


struct sip_set_autoanswer_PARAMETERS {
	bool auto_answer;
	int* result;
};


void sip_set_autoanswer(bool auto_answer, int* result)
{
	struct sip_set_autoanswer_PARAMETERS p;
	int i;

	p.auto_answer = auto_answer;

	p.result = result;

	Ipc_Send(g_sip_client, SIP_SET_AUTOANSWER, (void*)&p, sizeof(struct sip_set_autoanswer_PARAMETERS));

}


