#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"


#define QSTREAM_INIT_CALL	0
#define QSTREAM_Q_PRODUCT	1
#define QSTREAM_SET_CALL_REMOTE_IP	2
#define QSTREAM_START_CALL	3
#define QSTREAM_TERMINATE_CALL	4
#define QSTREAM_INVITE_CALL	5
#define QSTREAM_ABORT_CALL	6
#define QSTREAM_REJECT_CALL	7
#define QSTREAM_INIT_EARLY_MEDIA	8
#define QSTREAM_START_EARLY_MEDIA	9
#define QSTREAM_TERMINATE_EARLY_MEDIA	10
#define QSTREAM_HOLD_CALL	11
#define QSTREAM_RESUME_CALL	12
#define QSTREAM_SET_CALL_LOCAL_AUDIO_PORT	13
#define QSTREAM_SET_CALL_LOCAL_VIDEO_PORT	14
#define QSTREAM_SET_CALL_REMOTE_AUDIO_PORT	15
#define QSTREAM_SET_CALL_REMOTE_VIDEO_PORT	16
#define QSTREAM_SET_AUDIO_CODEC	17
#define QSTREAM_SET_AUDIO_CODEC_G7221_PARAMETERS	18
#define QSTREAM_SET_VIDEO_CODEC	19
#define QSTREAM_SET_DTMF_PT	20
#define QSTREAM_SWITCH_MODE_INIT	21
#define QSTREAM_SWITCH_MODE_START	22
#define QSTREAM_SET_MUTE	23
#define QSTREAM_SET_MIC_SOURCE	24
#define QSTREAM_SWITCH_VOICE_MODE	25
#define QSTREAM_SET_STREAM_QUALITY	26
#define QSTREAM_DTMF_TRANSMIT_MODE	27
#define QSTREAM_SEND_DTMF	28
#define QSTREAM_SEND_IDR	29
#define QSTREAM_FIRST_INCOMING_VIDEO_FRAME	30
#define QSTREAM_SNAPSHOT	31
#define QSTREAM_ADD_SMART_PHONE	32
#define QSTREAM_REMOVE_SMART_PHONE	33
#define QSTREAM_SELECT_HANDSET	34
#define QSTREAM_CHECK_STREAMING_MAPPING_TABLES	35
#define QSTREAM_PRINT_STREAMING_MAPPING_TABLE	36
#define QSTREAM_SET_CALL	37
#define QSTREAM_CONFERENCE_MODE_START	38
#define QSTREAM_CONFERENCE_MODE_STOP	39
#define QSTREAM_CHECK_VIDEO_RESOURCE_FROM_FW	40
#define QSTREAM_CHECK_VIDEO_RESOURCE_FROM_SIP	41
#define QSTREAM_PLAY_TONE	42
#define QSTREAM_SET_CAMERA_ZOOM	43
#define QSTREAM_SET_CAMERA_PAN_TILT	44


IpcSocket *g_qstream_client;


void qstream_Ipc_Client_Init(int listen_port)
{
	g_qstream_client = Ipc_Client_Init(listen_port);
}


void qstream_Ipc_Client_Destroy()
{
	Ipc_Client_Destroy(g_qstream_client);
}


struct qstream_init_call_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_init_call(int call_id, int* result)
{
	struct qstream_init_call_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_INIT_CALL, (void*)&p, sizeof(struct qstream_init_call_PARAMETERS));

}


struct qstream_q_product_PARAMETERS {
	int call_id;
	int isQProduct;
	int* result;
};


void qstream_q_product(int call_id, int isQProduct, int* result)
{
	struct qstream_q_product_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.isQProduct = isQProduct;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_Q_PRODUCT, (void*)&p, sizeof(struct qstream_q_product_PARAMETERS));

}


struct qstream_set_call_remote_ip_PARAMETERS {
	int call_id;
	int type;
	char dest_ip[128];
	int* result;
};


void qstream_set_call_remote_ip(int call_id, int type, char* dest_ip, int* result)
{
	struct qstream_set_call_remote_ip_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.type = type;

	strncpy(p.dest_ip, dest_ip, 128);

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SET_CALL_REMOTE_IP, (void*)&p, sizeof(struct qstream_set_call_remote_ip_PARAMETERS));

}


struct qstream_start_call_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_start_call(int call_id, int* result)
{
	struct qstream_start_call_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_START_CALL, (void*)&p, sizeof(struct qstream_start_call_PARAMETERS));

}


struct qstream_terminate_call_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_terminate_call(int call_id, int* result)
{
	struct qstream_terminate_call_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_TERMINATE_CALL, (void*)&p, sizeof(struct qstream_terminate_call_PARAMETERS));

}


struct qstream_invite_call_PARAMETERS {
	int call_id;
	int mode;
	int laudio_port;
	int lvideo_port;
	int* result;
};


void qstream_invite_call(int call_id, int mode, int laudio_port, int lvideo_port, int* result)
{
	struct qstream_invite_call_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.mode = mode;

	p.laudio_port = laudio_port;

	p.lvideo_port = lvideo_port;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_INVITE_CALL, (void*)&p, sizeof(struct qstream_invite_call_PARAMETERS));

}


struct qstream_abort_call_PARAMETERS {
	int call_id;
	int mode;
	int* result;
};


void qstream_abort_call(int call_id, int mode, int* result)
{
	struct qstream_abort_call_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_ABORT_CALL, (void*)&p, sizeof(struct qstream_abort_call_PARAMETERS));

}


struct qstream_reject_call_PARAMETERS {
	int call_id;
	int mode;
	int* result;
};


void qstream_reject_call(int call_id, int mode, int* result)
{
	struct qstream_reject_call_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_REJECT_CALL, (void*)&p, sizeof(struct qstream_reject_call_PARAMETERS));

}


struct qstream_init_early_media_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_init_early_media(int call_id, int* result)
{
	struct qstream_init_early_media_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_INIT_EARLY_MEDIA, (void*)&p, sizeof(struct qstream_init_early_media_PARAMETERS));

}


struct qstream_start_early_media_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_start_early_media(int call_id, int* result)
{
	struct qstream_start_early_media_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_START_EARLY_MEDIA, (void*)&p, sizeof(struct qstream_start_early_media_PARAMETERS));

}


struct qstream_terminate_early_media_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_terminate_early_media(int call_id, int* result)
{
	struct qstream_terminate_early_media_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_TERMINATE_EARLY_MEDIA, (void*)&p, sizeof(struct qstream_terminate_early_media_PARAMETERS));

}


struct qstream_hold_call_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_hold_call(int call_id, int* result)
{
	struct qstream_hold_call_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_HOLD_CALL, (void*)&p, sizeof(struct qstream_hold_call_PARAMETERS));

}


struct qstream_resume_call_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_resume_call(int call_id, int* result)
{
	struct qstream_resume_call_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_RESUME_CALL, (void*)&p, sizeof(struct qstream_resume_call_PARAMETERS));

}


struct qstream_set_call_local_audio_port_PARAMETERS {
	int call_id;
	int audio_port;
	int* result;
};


void qstream_set_call_local_audio_port(int call_id, int audio_port, int* result)
{
	struct qstream_set_call_local_audio_port_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.audio_port = audio_port;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SET_CALL_LOCAL_AUDIO_PORT, (void*)&p, sizeof(struct qstream_set_call_local_audio_port_PARAMETERS));

}


struct qstream_set_call_local_video_port_PARAMETERS {
	int call_id;
	int video_port;
	int* result;
};


void qstream_set_call_local_video_port(int call_id, int video_port, int* result)
{
	struct qstream_set_call_local_video_port_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.video_port = video_port;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SET_CALL_LOCAL_VIDEO_PORT, (void*)&p, sizeof(struct qstream_set_call_local_video_port_PARAMETERS));

}


struct qstream_set_call_remote_audio_port_PARAMETERS {
	int call_id;
	int audio_port;
	int* result;
};


void qstream_set_call_remote_audio_port(int call_id, int audio_port, int* result)
{
	struct qstream_set_call_remote_audio_port_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.audio_port = audio_port;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SET_CALL_REMOTE_AUDIO_PORT, (void*)&p, sizeof(struct qstream_set_call_remote_audio_port_PARAMETERS));

}


struct qstream_set_call_remote_video_port_PARAMETERS {
	int call_id;
	int video_port;
	int* result;
};


void qstream_set_call_remote_video_port(int call_id, int video_port, int* result)
{
	struct qstream_set_call_remote_video_port_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.video_port = video_port;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SET_CALL_REMOTE_VIDEO_PORT, (void*)&p, sizeof(struct qstream_set_call_remote_video_port_PARAMETERS));

}


struct qstream_set_audio_codec_PARAMETERS {
	int call_id;
	int audio_codec_type;
	char audio_payload[128];
	int* result;
};


void qstream_set_audio_codec(int call_id, int audio_codec_type, char* audio_payload, int* result)
{
	struct qstream_set_audio_codec_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.audio_codec_type = audio_codec_type;

	strncpy(p.audio_payload, audio_payload, 128);

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SET_AUDIO_CODEC, (void*)&p, sizeof(struct qstream_set_audio_codec_PARAMETERS));

}


struct qstream_set_audio_codec_g7221_parameters_PARAMETERS {
	int call_id;
	int sample_rate;
	int bit_rate;
	int* result;
};


void qstream_set_audio_codec_g7221_parameters(int call_id, int sample_rate, int bit_rate, int* result)
{
	struct qstream_set_audio_codec_g7221_parameters_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.sample_rate = sample_rate;

	p.bit_rate = bit_rate;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SET_AUDIO_CODEC_G7221_PARAMETERS, (void*)&p, sizeof(struct qstream_set_audio_codec_g7221_parameters_PARAMETERS));

}


struct qstream_set_video_codec_PARAMETERS {
	int call_id;
	int video_codec_type;
	char video_payload[128];
	int* result;
};


void qstream_set_video_codec(int call_id, int video_codec_type, char* video_payload, int* result)
{
	struct qstream_set_video_codec_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.video_codec_type = video_codec_type;

	strncpy(p.video_payload, video_payload, 128);

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SET_VIDEO_CODEC, (void*)&p, sizeof(struct qstream_set_video_codec_PARAMETERS));

}


struct qstream_set_dtmf_pt_PARAMETERS {
	int call_id;
	int dtmf_pt;
	int* result;
};


void qstream_set_dtmf_pt(int call_id, int dtmf_pt, int* result)
{
	struct qstream_set_dtmf_pt_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.dtmf_pt = dtmf_pt;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SET_DTMF_PT, (void*)&p, sizeof(struct qstream_set_dtmf_pt_PARAMETERS));

}


struct qstream_switch_mode_init_PARAMETERS {
	int call_id;
	int mode;
	int* result;
};


void qstream_switch_mode_init(int call_id, int mode, int* result)
{
	struct qstream_switch_mode_init_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SWITCH_MODE_INIT, (void*)&p, sizeof(struct qstream_switch_mode_init_PARAMETERS));

}


struct qstream_switch_mode_start_PARAMETERS {
	int call_id;
	int mode;
	int* result;
};


void qstream_switch_mode_start(int call_id, int mode, int* result)
{
	struct qstream_switch_mode_start_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SWITCH_MODE_START, (void*)&p, sizeof(struct qstream_switch_mode_start_PARAMETERS));

}


struct qstream_set_mute_PARAMETERS {
	int mode;
	bool IsEnable;
	int* result;
};


void qstream_set_mute(int mode, bool IsEnable, int* result)
{
	struct qstream_set_mute_PARAMETERS p;
	int i;

	p.mode = mode;

	p.IsEnable = IsEnable;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SET_MUTE, (void*)&p, sizeof(struct qstream_set_mute_PARAMETERS));

}


struct qstream_set_mic_source_PARAMETERS {
	int src_type;
	int* result;
};


void qstream_set_mic_source(int src_type, int* result)
{
	struct qstream_set_mic_source_PARAMETERS p;
	int i;

	p.src_type = src_type;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SET_MIC_SOURCE, (void*)&p, sizeof(struct qstream_set_mic_source_PARAMETERS));

}


struct qstream_switch_voice_mode_PARAMETERS {
	unsigned int mode;
	int* result;
};


void qstream_switch_voice_mode(unsigned int mode, int* result)
{
	struct qstream_switch_voice_mode_PARAMETERS p;
	int i;

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SWITCH_VOICE_MODE, (void*)&p, sizeof(struct qstream_switch_voice_mode_PARAMETERS));

}


struct qstream_set_stream_quality_PARAMETERS {
	unsigned int mode;
	int* result;
};


void qstream_set_stream_quality(unsigned int mode, int* result)
{
	struct qstream_set_stream_quality_PARAMETERS p;
	int i;

	p.mode = mode;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SET_STREAM_QUALITY, (void*)&p, sizeof(struct qstream_set_stream_quality_PARAMETERS));

}


struct qstream_dtmf_transmit_mode_PARAMETERS {
	int call_id;
	int transmit_mode;
	int* result;
};


void qstream_dtmf_transmit_mode(int call_id, int transmit_mode, int* result)
{
	struct qstream_dtmf_transmit_mode_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.transmit_mode = transmit_mode;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_DTMF_TRANSMIT_MODE, (void*)&p, sizeof(struct qstream_dtmf_transmit_mode_PARAMETERS));

}


struct qstream_send_dtmf_PARAMETERS {
	int call_id;
	int event;
	int duration;
	int* result;
};


void qstream_send_dtmf(int call_id, int event, int duration, int* result)
{
	struct qstream_send_dtmf_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.event = event;

	p.duration = duration;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SEND_DTMF, (void*)&p, sizeof(struct qstream_send_dtmf_PARAMETERS));

}


struct qstream_send_idr_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_send_idr(int call_id, int* result)
{
	struct qstream_send_idr_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SEND_IDR, (void*)&p, sizeof(struct qstream_send_idr_PARAMETERS));

}


struct qstream_first_incoming_video_frame_PARAMETERS {
	int* result;
};


void qstream_first_incoming_video_frame(int* result)
{
	struct qstream_first_incoming_video_frame_PARAMETERS p;
	int i;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_FIRST_INCOMING_VIDEO_FRAME, (void*)&p, sizeof(struct qstream_first_incoming_video_frame_PARAMETERS));

}


struct qstream_snapshot_PARAMETERS {
	char ori_path[128];
	char resize_path[128];
	int pos_x;
	int pos_y;
	int width;
	int height;
	int scale;
	int* result;
};


void qstream_snapshot(char* ori_path, char* resize_path, int pos_x, int pos_y, int width, int height, int scale, int* result)
{
	struct qstream_snapshot_PARAMETERS p;
	int i;

	strncpy(p.ori_path, ori_path, 128);

	strncpy(p.resize_path, resize_path, 128);

	p.pos_x = pos_x;

	p.pos_y = pos_y;

	p.width = width;

	p.height = height;

	p.scale = scale;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SNAPSHOT, (void*)&p, sizeof(struct qstream_snapshot_PARAMETERS));

}


struct qstream_add_smart_phone_PARAMETERS {
	int index;
	char ip_address[128];
	int remote_port;
	int* local_port;
	int* result;
};


void qstream_add_smart_phone(int index, char* ip_address, int remote_port, int* local_port, int* result)
{
	struct qstream_add_smart_phone_PARAMETERS p;
	int i;

	p.index = index;

	strncpy(p.ip_address, ip_address, 128);

	p.remote_port = remote_port;

	p.local_port = local_port;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_ADD_SMART_PHONE, (void*)&p, sizeof(struct qstream_add_smart_phone_PARAMETERS));

}


struct qstream_remove_smart_phone_PARAMETERS {
	int index;
	int* result;
};


void qstream_remove_smart_phone(int index, int* result)
{
	struct qstream_remove_smart_phone_PARAMETERS p;
	int i;

	p.index = index;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_REMOVE_SMART_PHONE, (void*)&p, sizeof(struct qstream_remove_smart_phone_PARAMETERS));

}


struct qstream_select_handset_PARAMETERS {
	int index;
	int* result;
};


void qstream_select_handset(int index, int* result)
{
	struct qstream_select_handset_PARAMETERS p;
	int i;

	p.index = index;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SELECT_HANDSET, (void*)&p, sizeof(struct qstream_select_handset_PARAMETERS));

}


struct qstream_check_streaming_mapping_tables_PARAMETERS {
	int* result;
};


void qstream_check_streaming_mapping_tables(int* result)
{
	struct qstream_check_streaming_mapping_tables_PARAMETERS p;
	int i;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_CHECK_STREAMING_MAPPING_TABLES, (void*)&p, sizeof(struct qstream_check_streaming_mapping_tables_PARAMETERS));

}


struct qstream_print_streaming_mapping_table_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_print_streaming_mapping_table(int call_id, int* result)
{
	struct qstream_print_streaming_mapping_table_PARAMETERS p;
	int i;

	p.call_id = call_id;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_PRINT_STREAMING_MAPPING_TABLE, (void*)&p, sizeof(struct qstream_print_streaming_mapping_table_PARAMETERS));

}


struct qstream_set_call_PARAMETERS {
	int call_id;
	char parameters[768];
	int* result;
};


void qstream_set_call(int call_id, void * parameters, int parameters_SIZE, int* result)
{
	struct qstream_set_call_PARAMETERS p;
	int i;

	p.call_id = call_id;

	memcpy(p.parameters, parameters, parameters_SIZE);

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_SET_CALL, (void*)&p, sizeof(struct qstream_set_call_PARAMETERS));

}


struct qstream_conference_mode_start_PARAMETERS {
	int* result;
};


void qstream_conference_mode_start(int* result)
{
	struct qstream_conference_mode_start_PARAMETERS p;
	int i;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_CONFERENCE_MODE_START, (void*)&p, sizeof(struct qstream_conference_mode_start_PARAMETERS));

}


struct qstream_conference_mode_stop_PARAMETERS {
	int* result;
};


void qstream_conference_mode_stop(int* result)
{
	struct qstream_conference_mode_stop_PARAMETERS p;
	int i;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_CONFERENCE_MODE_STOP, (void*)&p, sizeof(struct qstream_conference_mode_stop_PARAMETERS));

}


struct qstream_check_video_resource_from_fw_PARAMETERS {
};


void qstream_check_video_resource_from_fw()
{
	struct qstream_check_video_resource_from_fw_PARAMETERS p;
	int i;

	Ipc_Send(g_qstream_client, QSTREAM_CHECK_VIDEO_RESOURCE_FROM_FW, (void*)&p, sizeof(struct qstream_check_video_resource_from_fw_PARAMETERS));

}


struct qstream_check_video_resource_from_sip_PARAMETERS {
};


void qstream_check_video_resource_from_sip()
{
	struct qstream_check_video_resource_from_sip_PARAMETERS p;
	int i;

	Ipc_Send(g_qstream_client, QSTREAM_CHECK_VIDEO_RESOURCE_FROM_SIP, (void*)&p, sizeof(struct qstream_check_video_resource_from_sip_PARAMETERS));

}


struct qstream_play_tone_PARAMETERS {
	int tone_type;
	int* result;
};


void qstream_play_tone(int tone_type, int* result)
{
	struct qstream_play_tone_PARAMETERS p;
	int i;

	p.tone_type = tone_type;

	p.result = result;

	Ipc_Send(g_qstream_client, QSTREAM_PLAY_TONE, (void*)&p, sizeof(struct qstream_play_tone_PARAMETERS));

}


struct qstream_set_camera_zoom_PARAMETERS {
	long int ABSOLUTE;
};


void qstream_set_camera_zoom(long int ABSOLUTE)
{
	struct qstream_set_camera_zoom_PARAMETERS p;
	int i;

	p.ABSOLUTE = ABSOLUTE;

	Ipc_Send(g_qstream_client, QSTREAM_SET_CAMERA_ZOOM, (void*)&p, sizeof(struct qstream_set_camera_zoom_PARAMETERS));

}


struct qstream_set_camera_pan_tilt_PARAMETERS {
	short int pan;
	short int tilt;
};


void qstream_set_camera_pan_tilt(short int pan, short int tilt)
{
	struct qstream_set_camera_pan_tilt_PARAMETERS p;
	int i;

	p.pan = pan;

	p.tilt = tilt;

	Ipc_Send(g_qstream_client, QSTREAM_SET_CAMERA_PAN_TILT, (void*)&p, sizeof(struct qstream_set_camera_pan_tilt_PARAMETERS));

}


