/*
 *
 *  MTK driver for ofono/rilmodem
 *
 *  Copyright (C) 2014  Canonical Ltd.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include <stddef.h>

#include "mtkutil.h"
#include "mtk_constants.h"

const char *mtk_request_id_to_string(int req)
{
	switch (req) {
	case MTK_RIL_REQUEST_RADIO_POWEROFF:
		return "MTK_RIL_REQUEST_RADIO_POWEROFF";
	case MTK_RIL_REQUEST_DUAL_SIM_MODE_SWITCH:
		return "MTK_RIL_REQUEST_DUAL_SIM_MODE_SWITCH";
	case MTK_RIL_REQUEST_SET_GPRS_CONNECT_TYPE:
		return "MTK_RIL_REQUEST_SET_GPRS_CONNECT_TYPE";
	case MTK_RIL_REQUEST_SET_GPRS_TRANSFER_TYPE:
		return "MTK_RIL_REQUEST_SET_GPRS_TRANSFER_TYPE";
	case MTK_RIL_REQUEST_RADIO_POWERON:
		return "MTK_RIL_REQUEST_RADIO_POWERON";
	case MTK_RIL_REQUEST_SET_CALL_INDICATION:
		return "MTK_RIL_REQUEST_SET_CALL_INDICATION";
	case MTK_RIL_REQUEST_GET_3G_CAPABILITY:
		return "MTK_RIL_REQUEST_GET_3G_CAPABILITY";
	case MTK_RIL_REQUEST_SET_3G_CAPABILITY:
		return "MTK_RIL_REQUEST_SET_3G_CAPABILITY";
	case MTK_RIL_REQUEST_SET_TRM:
		return "MTK_RIL_REQUEST_SET_TRM";
	case MTK_RIL_REQUEST_SET_FD_MODE:
		return "MTK_RIL_REQUEST_SET_FD_MODE";
	case MTK_RIL_REQUEST_STORE_MODEM_TYPE:
		return "MTK_RIL_REQUEST_STORE_MODEM_TYPE";
	case MTK_RIL_REQUEST_RESUME_REGISTRATION:
		return "MTK_RIL_REQUEST_RESUME_REGISTRATION";
	case MTK_RIL_REQUEST_QUERY_MODEM_TYPE:
		return "MTK_RIL_REQUEST_QUERY_MODEM_TYPE";
	default:
		return NULL;
	}
}

const char *mtk_unsol_request_to_string(int req)
{
	switch (req) {
	case MTK_RIL_UNSOL_NEIGHBORING_CELL_INFO:
		return "MTK_RIL_UNSOL_NEIGHBORING_CELL_INFO";
	case MTK_RIL_UNSOL_NETWORK_INFO:
		return "MTK_RIL_UNSOL_NETWORK_INFO";
	case MTK_RIL_UNSOL_CALL_FORWARDING:
		return "MTK_RIL_UNSOL_CALL_FORWARDING";
	case MTK_RIL_UNSOL_CRSS_NOTIFICATION:
		return "MTK_RIL_UNSOL_CRSS_NOTIFICATION";
	case MTK_RIL_UNSOL_CALL_PROGRESS_INFO:
		return "MTK_RIL_UNSOL_CALL_PROGRESS_INFO";
	case MTK_RIL_UNSOL_PHB_READY_NOTIFICATION:
		return "MTK_RIL_UNSOL_PHB_READY_NOTIFICATION";
	case MTK_RIL_UNSOL_SPEECH_INFO:
		return "MTK_RIL_UNSOL_SPEECH_INFO";
	case MTK_RIL_UNSOL_SIM_INSERTED_STATUS:
		return "MTK_RIL_UNSOL_SIM_INSERTED_STATUS";
	case MTK_RIL_UNSOL_RADIO_TEMPORARILY_UNAVAILABLE:
		return "MTK_RIL_UNSOL_RADIO_TEMPORARILY_UNAVAILABLE";
	case MTK_RIL_UNSOL_ME_SMS_STORAGE_FULL:
		return "MTK_RIL_UNSOL_ME_SMS_STORAGE_FULL";
	case MTK_RIL_UNSOL_SMS_READY_NOTIFICATION:
		return "MTK_RIL_UNSOL_SMS_READY_NOTIFICATION";
	case MTK_RIL_UNSOL_SCRI_RESULT:
		return "MTK_RIL_UNSOL_SCRI_RESULT";
	case MTK_RIL_UNSOL_VT_STATUS_INFO:
		return "MTK_RIL_UNSOL_VT_STATUS_INFO";
	case MTK_RIL_UNSOL_VT_RING_INFO:
		return "MTK_RIL_UNSOL_VT_RING_INFO";
	case MTK_RIL_UNSOL_INCOMING_CALL_INDICATION:
		return "MTK_RIL_UNSOL_INCOMING_CALL_INDICATION";
	case MTK_RIL_UNSOL_SIM_MISSING:
		return "MTK_RIL_UNSOL_SIM_MISSING";
	case MTK_RIL_UNSOL_GPRS_DETACH:
		return "MTK_RIL_UNSOL_GPRS_DETACH";
	case MTK_RIL_UNSOL_ATCI_RESPONSE:
		return "MTK_RIL_UNSOL_ATCI_RESPONSE";
	case MTK_RIL_UNSOL_SIM_RECOVERY:
		return "MTK_RIL_UNSOL_SIM_RECOVERY";
	case MTK_RIL_UNSOL_VIRTUAL_SIM_ON:
		return "MTK_RIL_UNSOL_VIRTUAL_SIM_ON";
	case MTK_RIL_UNSOL_VIRTUAL_SIM_OFF:
		return "MTK_RIL_UNSOL_VIRTUAL_SIM_OFF";
	case MTK_RIL_UNSOL_INVALID_SIM:
		return "MTK_RIL_UNSOL_INVALID_SIM";
	case MTK_RIL_UNSOL_RESPONSE_PS_NETWORK_STATE_CHANGED:
		return "MTK_RIL_UNSOL_RESPONSE_PS_NETWORK_STATE_CHANGED";
	case MTK_RIL_UNSOL_RESPONSE_ACMT:
		return "MTK_RIL_UNSOL_RESPONSE_ACMT";
	case MTK_RIL_UNSOL_EF_CSP_PLMN_MODE_BIT:
		return "MTK_RIL_UNSOL_EF_CSP_PLMN_MODE_BIT";
	case MTK_RIL_UNSOL_IMEI_LOCK:
		return "MTK_RIL_UNSOL_IMEI_LOCK";
	case MTK_RIL_UNSOL_RESPONSE_MMRR_STATUS_CHANGED:
		return "MTK_RIL_UNSOL_RESPONSE_MMRR_STATUS_CHANGED";
	case MTK_RIL_UNSOL_SIM_PLUG_OUT:
		return "MTK_RIL_UNSOL_SIM_PLUG_OUT";
	case MTK_RIL_UNSOL_SIM_PLUG_IN:
		return "MTK_RIL_UNSOL_SIM_PLUG_IN";
	case MTK_RIL_UNSOL_RESPONSE_ETWS_NOTIFICATION:
		return "MTK_RIL_UNSOL_RESPONSE_ETWS_NOTIFICATION";
	case MTK_RIL_UNSOL_RESPONSE_PLMN_CHANGED:
		return "MTK_RIL_UNSOL_RESPONSE_PLMN_CHANGED";
	case MTK_RIL_UNSOL_RESPONSE_REGISTRATION_SUSPENDED:
		return "MTK_RIL_UNSOL_RESPONSE_REGISTRATION_SUSPENDED";
	case MTK_RIL_UNSOL_STK_EVDL_CALL:
		return "MTK_RIL_UNSOL_STK_EVDL_CALL";
	case MTK_RIL_UNSOL_DATA_PACKETS_FLUSH:
		return "MTK_RIL_UNSOL_DATA_PACKETS_FLUSH";
	case MTK_RIL_UNSOL_CIPHER_INDICATION:
		return "MTK_RIL_UNSOL_CIPHER_INDICATION";
	case MTK_RIL_UNSOL_FEMTOCELL_INFO:
		return "MTK_RIL_UNSOL_FEMTOCELL_INFO";
	case MTK_RIL_UNSOL_CNAP:
		return "MTK_RIL_UNSOL_CNAP";
	case MTK_RIL_UNSOL_RAC_UPDATE:
		return "MTK_RIL_UNSOL_RAC_UPDATE";
	default:
		return NULL;
	}
}