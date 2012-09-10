#ifndef IPC_FRAMEWORK_CLIENT_H
#define IPC_FRAMEWORK_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"




void framework_Ipc_Client_Init(int listen_port);
void framework_Ipc_Client_Destroy();


void fw_incoming_call(char* user_name, char* phone_number, unsigned int mode, int* result);
void fw_outgoing_identify(char* phone_number, char* new_name, char* new_number, int* result);
void fw_outbound_timeout(char* user_name, char* phone_number, int* result);
void fw_inbound_answer(char* user_name, char* phone_number, unsigned int mode, int* result);
void fw_inbound_timeout(char* user_name, char* phone_number, int* result);
void fw_inbound_terminate_call(char* user_name, char* phone_number, int* result);
void fw_inbound_hold_call(char* user_name, char* phone_number, int* result);
void fw_inbound_resume_call(char* user_name, char* phone_number, int* result);
void fw_outbound_hold_call_cancel(char* user_name, char* phone_number, int* result);
void fw_inbound_mute(char* user_name, char* phone_number, int isMute, int* result);
void fw_inbound_request_switch(char* user_name, char* phone_number, unsigned int mode, int* result);
void fw_inbound_confirm_switch(unsigned int accept, char* user_name, char* phone_number, unsigned int mode, int* result);
void fw_outbound_request_switch_cancel(char* user_name, char* phone_number, unsigned int mode, int* result);
void fw_inbound_request_switch_cancel(char* user_name, char* phone_number, unsigned int mode, int* result);
void fw_conference_incoming_call(char* user_name, char* phone_number, unsigned int mode, int* result);
void fw_inbound_conference_resume(char* user_name, char* phone_number, int* result);
void fw_conference_notify(char* user_name, char* phone_number, unsigned int mode, int number_of_participant, int* result);
void fw_early_dtmf(char* user_name, char* phone_number, int* result);
void fw_set_message(unsigned int message_type, unsigned int count, int* result);
void fw_register(int isRegister, int* result);
void fw_register_timeout(int* result);
void fw_first_incoming_video_frame(char* phone_number, int* result);
void fw_set_framebuffer(char* phone_number, int fb, int* result);
void fw_set_remote_view_resolution(char* phone_number, int width, int height, int* result);
void fw_remote_transaction_begin(char* phone_number, int* result);
void fw_remote_transaction_end(char* phone_number, int* result);
void fw_set_local_view_resolution(int width, int height, int* result);
void fw_local_view_begin(int* result);
void fw_local_view_end(int* result);
void fw_visual_indicator(int level, int* result);
void fw_remote_video_terminate_alert(int* result);
void fw_play_ringbacktone(int ring, int* result);
void cm_accept_call(char* user_name, char* phone_number, int* result);
void cm_hold_call(char* user_name, char* phone_number, int* result);
void cm_resume_call(char* user_name, char* phone_number, int* result);
void cm_swap_call(char* user_name, char* phone_number, int* result);
void fw_receive_test_key(int key_code, int* result);
void fw_stb_res_cb(int width, int height, int* result);
void fw_network_detector_cb(char* interface, int network_status, int ip_changed, int* result);
void fw_notify_update_config(int notify, int* result);
void fw_set_product(char* phone_number, int product_type, int* result);
void fw_event_exception_handle(int component_type, int error_code, int action, int* result);
void fw_outgoing_transfer(char* phone_number, char* new_name, char* new_number, unsigned int mode, int* result);
void fw_incoming_transfer(char* phone_number, char* new_name, char* new_number, unsigned int mode, int* result);
void fw_forward_call(char* phone_number, char* new_name, char* new_number, unsigned int mode, int* result);


#endif
