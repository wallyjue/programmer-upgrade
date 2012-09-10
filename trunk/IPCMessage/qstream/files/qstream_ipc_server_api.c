#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"
#include <stdbool.h>


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


int qstream_COMMAND_HANDLER(int command_type, void* parameters);


IpcSocket *g_qstream_server;


void qstream_Ipc_Server_Init(int listen_port)
{
	g_qstream_server = Ipc_Server_Init(listen_port, qstream_COMMAND_HANDLER);
}


void qstream_Ipc_Server_Destroy()
{
	Ipc_Server_Destroy(g_qstream_server);
}


struct qstream_init_call_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_init_call_EXECUTE(struct qstream_init_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_init_call(parameters->call_id, parameters->result);

	free(parameters->result);
}


struct qstream_q_product_PARAMETERS {
	int call_id;
	int isQProduct;
	int* result;
};


void qstream_q_product_EXECUTE(struct qstream_q_product_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_q_product(parameters->call_id, parameters->isQProduct, parameters->result);

	free(parameters->result);
}


struct qstream_set_call_remote_ip_PARAMETERS {
	int call_id;
	int type;
	char dest_ip[128];
	int* result;
};


void qstream_set_call_remote_ip_EXECUTE(struct qstream_set_call_remote_ip_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_set_call_remote_ip(parameters->call_id, parameters->type, parameters->dest_ip, parameters->result);

	free(parameters->result);
}


struct qstream_start_call_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_start_call_EXECUTE(struct qstream_start_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_start_call(parameters->call_id, parameters->result);

	free(parameters->result);
}


struct qstream_terminate_call_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_terminate_call_EXECUTE(struct qstream_terminate_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_terminate_call(parameters->call_id, parameters->result);

	free(parameters->result);
}


struct qstream_invite_call_PARAMETERS {
	int call_id;
	int mode;
	int laudio_port;
	int lvideo_port;
	int* result;
};


void qstream_invite_call_EXECUTE(struct qstream_invite_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_invite_call(parameters->call_id, parameters->mode, parameters->laudio_port, parameters->lvideo_port, parameters->result);

	free(parameters->result);
}


struct qstream_abort_call_PARAMETERS {
	int call_id;
	int mode;
	int* result;
};


void qstream_abort_call_EXECUTE(struct qstream_abort_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_abort_call(parameters->call_id, parameters->mode, parameters->result);

	free(parameters->result);
}


struct qstream_reject_call_PARAMETERS {
	int call_id;
	int mode;
	int* result;
};


void qstream_reject_call_EXECUTE(struct qstream_reject_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_reject_call(parameters->call_id, parameters->mode, parameters->result);

	free(parameters->result);
}


struct qstream_init_early_media_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_init_early_media_EXECUTE(struct qstream_init_early_media_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_init_early_media(parameters->call_id, parameters->result);

	free(parameters->result);
}


struct qstream_start_early_media_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_start_early_media_EXECUTE(struct qstream_start_early_media_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_start_early_media(parameters->call_id, parameters->result);

	free(parameters->result);
}


struct qstream_terminate_early_media_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_terminate_early_media_EXECUTE(struct qstream_terminate_early_media_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_terminate_early_media(parameters->call_id, parameters->result);

	free(parameters->result);
}


struct qstream_hold_call_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_hold_call_EXECUTE(struct qstream_hold_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_hold_call(parameters->call_id, parameters->result);

	free(parameters->result);
}


struct qstream_resume_call_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_resume_call_EXECUTE(struct qstream_resume_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_resume_call(parameters->call_id, parameters->result);

	free(parameters->result);
}


struct qstream_set_call_local_audio_port_PARAMETERS {
	int call_id;
	int audio_port;
	int* result;
};


void qstream_set_call_local_audio_port_EXECUTE(struct qstream_set_call_local_audio_port_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_set_call_local_audio_port(parameters->call_id, parameters->audio_port, parameters->result);

	free(parameters->result);
}


struct qstream_set_call_local_video_port_PARAMETERS {
	int call_id;
	int video_port;
	int* result;
};


void qstream_set_call_local_video_port_EXECUTE(struct qstream_set_call_local_video_port_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_set_call_local_video_port(parameters->call_id, parameters->video_port, parameters->result);

	free(parameters->result);
}


struct qstream_set_call_remote_audio_port_PARAMETERS {
	int call_id;
	int audio_port;
	int* result;
};


void qstream_set_call_remote_audio_port_EXECUTE(struct qstream_set_call_remote_audio_port_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_set_call_remote_audio_port(parameters->call_id, parameters->audio_port, parameters->result);

	free(parameters->result);
}


struct qstream_set_call_remote_video_port_PARAMETERS {
	int call_id;
	int video_port;
	int* result;
};


void qstream_set_call_remote_video_port_EXECUTE(struct qstream_set_call_remote_video_port_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_set_call_remote_video_port(parameters->call_id, parameters->video_port, parameters->result);

	free(parameters->result);
}


struct qstream_set_audio_codec_PARAMETERS {
	int call_id;
	int audio_codec_type;
	char audio_payload[128];
	int* result;
};


void qstream_set_audio_codec_EXECUTE(struct qstream_set_audio_codec_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_set_audio_codec(parameters->call_id, parameters->audio_codec_type, parameters->audio_payload, parameters->result);

	free(parameters->result);
}


struct qstream_set_audio_codec_g7221_parameters_PARAMETERS {
	int call_id;
	int sample_rate;
	int bit_rate;
	int* result;
};


void qstream_set_audio_codec_g7221_parameters_EXECUTE(struct qstream_set_audio_codec_g7221_parameters_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_set_audio_codec_g7221_parameters(parameters->call_id, parameters->sample_rate, parameters->bit_rate, parameters->result);

	free(parameters->result);
}


struct qstream_set_video_codec_PARAMETERS {
	int call_id;
	int video_codec_type;
	char video_payload[128];
	int* result;
};


void qstream_set_video_codec_EXECUTE(struct qstream_set_video_codec_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_set_video_codec(parameters->call_id, parameters->video_codec_type, parameters->video_payload, parameters->result);

	free(parameters->result);
}


struct qstream_set_dtmf_pt_PARAMETERS {
	int call_id;
	int dtmf_pt;
	int* result;
};


void qstream_set_dtmf_pt_EXECUTE(struct qstream_set_dtmf_pt_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_set_dtmf_pt(parameters->call_id, parameters->dtmf_pt, parameters->result);

	free(parameters->result);
}


struct qstream_switch_mode_init_PARAMETERS {
	int call_id;
	int mode;
	int* result;
};


void qstream_switch_mode_init_EXECUTE(struct qstream_switch_mode_init_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_switch_mode_init(parameters->call_id, parameters->mode, parameters->result);

	free(parameters->result);
}


struct qstream_switch_mode_start_PARAMETERS {
	int call_id;
	int mode;
	int* result;
};


void qstream_switch_mode_start_EXECUTE(struct qstream_switch_mode_start_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_switch_mode_start(parameters->call_id, parameters->mode, parameters->result);

	free(parameters->result);
}


struct qstream_set_mute_PARAMETERS {
	int mode;
	bool IsEnable;
	int* result;
};


void qstream_set_mute_EXECUTE(struct qstream_set_mute_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_set_mute(parameters->mode, parameters->IsEnable, parameters->result);

	free(parameters->result);
}


struct qstream_set_mic_source_PARAMETERS {
	int src_type;
	int* result;
};


void qstream_set_mic_source_EXECUTE(struct qstream_set_mic_source_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_set_mic_source(parameters->src_type, parameters->result);

	free(parameters->result);
}


struct qstream_switch_voice_mode_PARAMETERS {
	unsigned int mode;
	int* result;
};


void qstream_switch_voice_mode_EXECUTE(struct qstream_switch_voice_mode_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_switch_voice_mode(parameters->mode, parameters->result);

	free(parameters->result);
}


struct qstream_set_stream_quality_PARAMETERS {
	unsigned int mode;
	int* result;
};


void qstream_set_stream_quality_EXECUTE(struct qstream_set_stream_quality_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_set_stream_quality(parameters->mode, parameters->result);

	free(parameters->result);
}


struct qstream_dtmf_transmit_mode_PARAMETERS {
	int call_id;
	int transmit_mode;
	int* result;
};


void qstream_dtmf_transmit_mode_EXECUTE(struct qstream_dtmf_transmit_mode_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_dtmf_transmit_mode(parameters->call_id, parameters->transmit_mode, parameters->result);

	free(parameters->result);
}


struct qstream_send_dtmf_PARAMETERS {
	int call_id;
	int event;
	int duration;
	int* result;
};


void qstream_send_dtmf_EXECUTE(struct qstream_send_dtmf_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_send_dtmf(parameters->call_id, parameters->event, parameters->duration, parameters->result);

	free(parameters->result);
}


struct qstream_send_idr_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_send_idr_EXECUTE(struct qstream_send_idr_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_send_idr(parameters->call_id, parameters->result);

	free(parameters->result);
}


struct qstream_first_incoming_video_frame_PARAMETERS {
	int* result;
};


void qstream_first_incoming_video_frame_EXECUTE(struct qstream_first_incoming_video_frame_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_first_incoming_video_frame(parameters->result);

	free(parameters->result);
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


void qstream_snapshot_EXECUTE(struct qstream_snapshot_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_snapshot(parameters->ori_path, parameters->resize_path, parameters->pos_x, parameters->pos_y, parameters->width, parameters->height, parameters->scale, parameters->result);

	free(parameters->result);
}


struct qstream_add_smart_phone_PARAMETERS {
	int index;
	char ip_address[128];
	int remote_port;
	int* local_port;
	int* result;
};


void qstream_add_smart_phone_EXECUTE(struct qstream_add_smart_phone_PARAMETERS *parameters)
{
	parameters->local_port = (int*)malloc(sizeof(int));

	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_add_smart_phone(parameters->index, parameters->ip_address, parameters->remote_port, parameters->local_port, parameters->result);

	free(parameters->local_port);
	free(parameters->result);
}


struct qstream_remove_smart_phone_PARAMETERS {
	int index;
	int* result;
};


void qstream_remove_smart_phone_EXECUTE(struct qstream_remove_smart_phone_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_remove_smart_phone(parameters->index, parameters->result);

	free(parameters->result);
}


struct qstream_select_handset_PARAMETERS {
	int index;
	int* result;
};


void qstream_select_handset_EXECUTE(struct qstream_select_handset_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_select_handset(parameters->index, parameters->result);

	free(parameters->result);
}


struct qstream_check_streaming_mapping_tables_PARAMETERS {
	int* result;
};


void qstream_check_streaming_mapping_tables_EXECUTE(struct qstream_check_streaming_mapping_tables_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_check_streaming_mapping_tables(parameters->result);

	free(parameters->result);
}


struct qstream_print_streaming_mapping_table_PARAMETERS {
	int call_id;
	int* result;
};


void qstream_print_streaming_mapping_table_EXECUTE(struct qstream_print_streaming_mapping_table_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_print_streaming_mapping_table(parameters->call_id, parameters->result);

	free(parameters->result);
}


struct qstream_set_call_PARAMETERS {
	int call_id;
	char parameters[768];
	int* result;
};


void qstream_set_call_EXECUTE(struct qstream_set_call_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_set_call(parameters->call_id, parameters->parameters, parameters->result);

	free(parameters->result);
}


struct qstream_conference_mode_start_PARAMETERS {
	int* result;
};


void qstream_conference_mode_start_EXECUTE(struct qstream_conference_mode_start_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_conference_mode_start(parameters->result);

	free(parameters->result);
}


struct qstream_conference_mode_stop_PARAMETERS {
	int* result;
};


void qstream_conference_mode_stop_EXECUTE(struct qstream_conference_mode_stop_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_conference_mode_stop(parameters->result);

	free(parameters->result);
}


struct qstream_check_video_resource_from_fw_PARAMETERS {
};


void qstream_check_video_resource_from_fw_EXECUTE(struct qstream_check_video_resource_from_fw_PARAMETERS *parameters)
{
	embeddedvc_qstream_check_video_resource_from_fw();

}


struct qstream_check_video_resource_from_sip_PARAMETERS {
};


void qstream_check_video_resource_from_sip_EXECUTE(struct qstream_check_video_resource_from_sip_PARAMETERS *parameters)
{
	embeddedvc_qstream_check_video_resource_from_sip();

}


struct qstream_play_tone_PARAMETERS {
	int tone_type;
	int* result;
};


void qstream_play_tone_EXECUTE(struct qstream_play_tone_PARAMETERS *parameters)
{
	parameters->result = (int*)malloc(sizeof(int));

	embeddedvc_qstream_play_tone(parameters->tone_type, parameters->result);

	free(parameters->result);
}


struct qstream_set_camera_zoom_PARAMETERS {
	long int ABSOLUTE;
};


void qstream_set_camera_zoom_EXECUTE(struct qstream_set_camera_zoom_PARAMETERS *parameters)
{
	embeddedvc_qstream_set_camera_zoom(parameters->ABSOLUTE);

}


struct qstream_set_camera_pan_tilt_PARAMETERS {
	short int pan;
	short int tilt;
};


void qstream_set_camera_pan_tilt_EXECUTE(struct qstream_set_camera_pan_tilt_PARAMETERS *parameters)
{
	embeddedvc_qstream_set_camera_pan_tilt(parameters->pan, parameters->tilt);

}


int qstream_COMMAND_HANDLER(int command_type, void* parameters)
{
	switch (command_type) {
		case QSTREAM_INIT_CALL:
			qstream_init_call_EXECUTE((struct qstream_init_call_PARAMETERS *)parameters);
			break;
		case QSTREAM_Q_PRODUCT:
			qstream_q_product_EXECUTE((struct qstream_q_product_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_CALL_REMOTE_IP:
			qstream_set_call_remote_ip_EXECUTE((struct qstream_set_call_remote_ip_PARAMETERS *)parameters);
			break;
		case QSTREAM_START_CALL:
			qstream_start_call_EXECUTE((struct qstream_start_call_PARAMETERS *)parameters);
			break;
		case QSTREAM_TERMINATE_CALL:
			qstream_terminate_call_EXECUTE((struct qstream_terminate_call_PARAMETERS *)parameters);
			break;
		case QSTREAM_INVITE_CALL:
			qstream_invite_call_EXECUTE((struct qstream_invite_call_PARAMETERS *)parameters);
			break;
		case QSTREAM_ABORT_CALL:
			qstream_abort_call_EXECUTE((struct qstream_abort_call_PARAMETERS *)parameters);
			break;
		case QSTREAM_REJECT_CALL:
			qstream_reject_call_EXECUTE((struct qstream_reject_call_PARAMETERS *)parameters);
			break;
		case QSTREAM_INIT_EARLY_MEDIA:
			qstream_init_early_media_EXECUTE((struct qstream_init_early_media_PARAMETERS *)parameters);
			break;
		case QSTREAM_START_EARLY_MEDIA:
			qstream_start_early_media_EXECUTE((struct qstream_start_early_media_PARAMETERS *)parameters);
			break;
		case QSTREAM_TERMINATE_EARLY_MEDIA:
			qstream_terminate_early_media_EXECUTE((struct qstream_terminate_early_media_PARAMETERS *)parameters);
			break;
		case QSTREAM_HOLD_CALL:
			qstream_hold_call_EXECUTE((struct qstream_hold_call_PARAMETERS *)parameters);
			break;
		case QSTREAM_RESUME_CALL:
			qstream_resume_call_EXECUTE((struct qstream_resume_call_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_CALL_LOCAL_AUDIO_PORT:
			qstream_set_call_local_audio_port_EXECUTE((struct qstream_set_call_local_audio_port_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_CALL_LOCAL_VIDEO_PORT:
			qstream_set_call_local_video_port_EXECUTE((struct qstream_set_call_local_video_port_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_CALL_REMOTE_AUDIO_PORT:
			qstream_set_call_remote_audio_port_EXECUTE((struct qstream_set_call_remote_audio_port_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_CALL_REMOTE_VIDEO_PORT:
			qstream_set_call_remote_video_port_EXECUTE((struct qstream_set_call_remote_video_port_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_AUDIO_CODEC:
			qstream_set_audio_codec_EXECUTE((struct qstream_set_audio_codec_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_AUDIO_CODEC_G7221_PARAMETERS:
			qstream_set_audio_codec_g7221_parameters_EXECUTE((struct qstream_set_audio_codec_g7221_parameters_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_VIDEO_CODEC:
			qstream_set_video_codec_EXECUTE((struct qstream_set_video_codec_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_DTMF_PT:
			qstream_set_dtmf_pt_EXECUTE((struct qstream_set_dtmf_pt_PARAMETERS *)parameters);
			break;
		case QSTREAM_SWITCH_MODE_INIT:
			qstream_switch_mode_init_EXECUTE((struct qstream_switch_mode_init_PARAMETERS *)parameters);
			break;
		case QSTREAM_SWITCH_MODE_START:
			qstream_switch_mode_start_EXECUTE((struct qstream_switch_mode_start_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_MUTE:
			qstream_set_mute_EXECUTE((struct qstream_set_mute_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_MIC_SOURCE:
			qstream_set_mic_source_EXECUTE((struct qstream_set_mic_source_PARAMETERS *)parameters);
			break;
		case QSTREAM_SWITCH_VOICE_MODE:
			qstream_switch_voice_mode_EXECUTE((struct qstream_switch_voice_mode_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_STREAM_QUALITY:
			qstream_set_stream_quality_EXECUTE((struct qstream_set_stream_quality_PARAMETERS *)parameters);
			break;
		case QSTREAM_DTMF_TRANSMIT_MODE:
			qstream_dtmf_transmit_mode_EXECUTE((struct qstream_dtmf_transmit_mode_PARAMETERS *)parameters);
			break;
		case QSTREAM_SEND_DTMF:
			qstream_send_dtmf_EXECUTE((struct qstream_send_dtmf_PARAMETERS *)parameters);
			break;
		case QSTREAM_SEND_IDR:
			qstream_send_idr_EXECUTE((struct qstream_send_idr_PARAMETERS *)parameters);
			break;
		case QSTREAM_FIRST_INCOMING_VIDEO_FRAME:
			qstream_first_incoming_video_frame_EXECUTE((struct qstream_first_incoming_video_frame_PARAMETERS *)parameters);
			break;
		case QSTREAM_SNAPSHOT:
			qstream_snapshot_EXECUTE((struct qstream_snapshot_PARAMETERS *)parameters);
			break;
		case QSTREAM_ADD_SMART_PHONE:
			qstream_add_smart_phone_EXECUTE((struct qstream_add_smart_phone_PARAMETERS *)parameters);
			break;
		case QSTREAM_REMOVE_SMART_PHONE:
			qstream_remove_smart_phone_EXECUTE((struct qstream_remove_smart_phone_PARAMETERS *)parameters);
			break;
		case QSTREAM_SELECT_HANDSET:
			qstream_select_handset_EXECUTE((struct qstream_select_handset_PARAMETERS *)parameters);
			break;
		case QSTREAM_CHECK_STREAMING_MAPPING_TABLES:
			qstream_check_streaming_mapping_tables_EXECUTE((struct qstream_check_streaming_mapping_tables_PARAMETERS *)parameters);
			break;
		case QSTREAM_PRINT_STREAMING_MAPPING_TABLE:
			qstream_print_streaming_mapping_table_EXECUTE((struct qstream_print_streaming_mapping_table_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_CALL:
			qstream_set_call_EXECUTE((struct qstream_set_call_PARAMETERS *)parameters);
			break;
		case QSTREAM_CONFERENCE_MODE_START:
			qstream_conference_mode_start_EXECUTE((struct qstream_conference_mode_start_PARAMETERS *)parameters);
			break;
		case QSTREAM_CONFERENCE_MODE_STOP:
			qstream_conference_mode_stop_EXECUTE((struct qstream_conference_mode_stop_PARAMETERS *)parameters);
			break;
		case QSTREAM_CHECK_VIDEO_RESOURCE_FROM_FW:
			qstream_check_video_resource_from_fw_EXECUTE((struct qstream_check_video_resource_from_fw_PARAMETERS *)parameters);
			break;
		case QSTREAM_CHECK_VIDEO_RESOURCE_FROM_SIP:
			qstream_check_video_resource_from_sip_EXECUTE((struct qstream_check_video_resource_from_sip_PARAMETERS *)parameters);
			break;
		case QSTREAM_PLAY_TONE:
			qstream_play_tone_EXECUTE((struct qstream_play_tone_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_CAMERA_ZOOM:
			qstream_set_camera_zoom_EXECUTE((struct qstream_set_camera_zoom_PARAMETERS *)parameters);
			break;
		case QSTREAM_SET_CAMERA_PAN_TILT:
			qstream_set_camera_pan_tilt_EXECUTE((struct qstream_set_camera_pan_tilt_PARAMETERS *)parameters);
			break;
		default:
			return -1;
			break;
	}

	return 0;
}
