#ifndef IPC_SIP_CLIENT_H
#define IPC_SIP_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"




void sip_Ipc_Client_Init(int listen_port);
void sip_Ipc_Client_Destroy();


void sip_make_registration(char* URI, char* proxy, char* realm, char* sipid, char* name, char* psw, int* result);
void sip_make_call(unsigned int mode, char* addr, int audio_source, int* result);
void sip_set_call_rejection(char* addr, int* result);
void sip_hold_call(char* addr, int* result);
void sip_resume_call(char* addr, int* result);
void sip_request_switch(int mode, char* addr, int* result);
void sip_confirm_switch(int accept, int mode, char* addr, int* result);
void sip_start_conference_call(char* addr1, char* addr2, int* result);
void sip_start_video_conference_call(int* result);
void sip_make_video_conference_call(char* addr, int* result);
void sip_video_conference_hold_call(char* addr, int* result);
void sip_video_conference_resume_call(char* addr, int* result);
void sip_terminate_call(char* addr, int* result);
void sip_cancel_call(char* addr, int* result);
void sip_answer_call(int mode, char* addr, int audio_source, int* result);
void sip_reject_call(char* addr, int* result);
void sip_set_dnd(bool IsDND, int* result);
void sip_set_call_forwarding(int mode, int type, char* addr, int* result);
void sip_set_call_waiting(bool IsWait, int* result);
void sip_swap_waiting_call(char* active_addr, char* hold_addr, int* result);
void sip_unattend_transfer(char* addr, char* target_addr, int* result);
void sip_attend_transfer(char* addr, char* target_addr, int* result);
void sip_forward_call(char* addr, char* target_addr, int* result);
void sip_set_invite_progress(bool inviteProgress, int* result);
void sip_get_seesion(char* addr, int* result);
void sip_transmit_dtmf(char* addr, int event, int duration, int* result);
void sip_info_dtmf(char* addr, int event, int duration, int* result);
void sip_get_message(unsigned int message_type, int* result);
void sip_request_idr(int session, int* result);
void sip_restart(int* result);
void sip_register(int* result);
void sip_set_autoanswer(bool auto_answer, int* result);


#endif
