#ifndef IPC_QSTREAM_CLIENT_H
#define IPC_QSTREAM_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"




void qstream_Ipc_Client_Init(int listen_port);
void qstream_Ipc_Client_Destroy();


void qstream_init_call(int call_id, int* result);
void qstream_q_product(int call_id, int isQProduct, int* result);
void qstream_set_call_remote_ip(int call_id, int type, char* dest_ip, int* result);
void qstream_start_call(int call_id, int* result);
void qstream_terminate_call(int call_id, int* result);
void qstream_invite_call(int call_id, int mode, int laudio_port, int lvideo_port, int* result);
void qstream_abort_call(int call_id, int mode, int* result);
void qstream_reject_call(int call_id, int mode, int* result);
void qstream_init_early_media(int call_id, int* result);
void qstream_start_early_media(int call_id, int* result);
void qstream_terminate_early_media(int call_id, int* result);
void qstream_hold_call(int call_id, int* result);
void qstream_resume_call(int call_id, int* result);
void qstream_set_call_local_audio_port(int call_id, int audio_port, int* result);
void qstream_set_call_local_video_port(int call_id, int video_port, int* result);
void qstream_set_call_remote_audio_port(int call_id, int audio_port, int* result);
void qstream_set_call_remote_video_port(int call_id, int video_port, int* result);
void qstream_set_audio_codec(int call_id, int audio_codec_type, char* audio_payload, int* result);
void qstream_set_audio_codec_g7221_parameters(int call_id, int sample_rate, int bit_rate, int* result);
void qstream_set_video_codec(int call_id, int video_codec_type, char* video_payload, int* result);
void qstream_set_dtmf_pt(int call_id, int dtmf_pt, int* result);
void qstream_switch_mode_init(int call_id, int mode, int* result);
void qstream_switch_mode_start(int call_id, int mode, int* result);
void qstream_set_mute(int mode, bool IsEnable, int* result);
void qstream_set_mic_source(int src_type, int* result);
void qstream_switch_voice_mode(unsigned int mode, int* result);
void qstream_set_stream_quality(unsigned int mode, int* result);
void qstream_dtmf_transmit_mode(int call_id, int transmit_mode, int* result);
void qstream_send_dtmf(int call_id, int event, int duration, int* result);
void qstream_send_idr(int call_id, int* result);
void qstream_first_incoming_video_frame(int* result);
void qstream_snapshot(char* ori_path, char* resize_path, int pos_x, int pos_y, int width, int height, int scale, int* result);
void qstream_add_smart_phone(int index, char* ip_address, int remote_port, int* local_port, int* result);
void qstream_remove_smart_phone(int index, int* result);
void qstream_select_handset(int index, int* result);
void qstream_check_streaming_mapping_tables(int* result);
void qstream_print_streaming_mapping_table(int call_id, int* result);
void qstream_set_call(int call_id, void* parameters, int parameters_SIZE, int* result);
void qstream_conference_mode_start(int* result);
void qstream_conference_mode_stop(int* result);
void qstream_check_video_resource_from_fw();
void qstream_check_video_resource_from_sip();
void qstream_play_tone(int tone_type, int* result);
void qstream_set_camera_zoom(long int ABSOLUTE);
void qstream_set_camera_pan_tilt(short int pan, short int tilt);


#endif
