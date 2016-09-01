/*
 *
 *  oFono - Open Source Telephony
 *
 *  Copyright (C) 2014 Canonical Ltd.
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <glib.h>
#include <errno.h>

#include <ofono/modem.h>
#include <ofono/gprs-context.h>
#include <ofono/types.h>

#include "gril.h"
#include "grilunsol.h"

#include "drivers/mtkmodem/mtk_constants.h"
#include "drivers/mtkmodem/mtkunsol.h"

/*
 * As all our architectures are little-endian except for
 * PowerPC, and the Binder wire-format differs slightly
 * depending on endian-ness, the following guards against test
 * failures when run on PowerPC.
 */
#if BYTE_ORDER == LITTLE_ENDIAN

/*
 * The following hexadecimal data represents a serialized Binder parcel instance
 * containing a valid MTK_RIL_UNSOL_INCOMING_CALL_INDICATION message with the
 * following parameters:
 *
 * {1,677777777,161,0,1}
 */
static const guchar unsol_incoming_call_indication_parcel1[] = {
	0x05, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00,
	0x09, 0x00, 0x00, 0x00, 0x36, 0x00, 0x37, 0x00, 0x37, 0x00, 0x37, 0x00,
	0x37, 0x00, 0x37, 0x00, 0x37, 0x00, 0x37, 0x00, 0x37, 0x00, 0x00, 0x00,
	0x03, 0x00, 0x00, 0x00, 0x31, 0x00, 0x36, 0x00, 0x31, 0x00, 0x00, 0x00,
	0x01, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
	0x31, 0x00, 0x00, 0x00
};

static const struct ril_msg unsol_incoming_call_indication_valid_1 = {
	.buf = (gchar *) &unsol_incoming_call_indication_parcel1,
	.buf_len = sizeof(unsol_incoming_call_indication_parcel1),
	.unsolicited = TRUE,
	.req = MTK_RIL_UNSOL_INCOMING_CALL_INDICATION,
	.serial_no = 0,
	.error = 0,
};

/*
 * The following hexadecimal data represents a serialized Binder parcel instance
 * containing a valid MTK_RIL_UNSOL_RESPONSE_REGISTRATION_SUSPENDED message with
 * the following parameters:
 *
 * {1}
 */
static const guchar unsol_registration_suspended_parcel1[] = {
	0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
};

static const struct ril_msg unsol_registration_suspended_valid_1 = {
	.buf = (gchar *) &unsol_registration_suspended_parcel1,
	.buf_len = sizeof(unsol_registration_suspended_parcel1),
	.unsolicited = TRUE,
	.req = MTK_RIL_UNSOL_RESPONSE_REGISTRATION_SUSPENDED,
	.serial_no = 0,
	.error = 0,
};

/*
 * The following hexadecimal data represents a serialized Binder parcel instance
 * containing a valid MTK_RIL_UNSOL_RESPONSE_PLMN_CHANGED message with the
 * following parameters:
 *
 * {21401}
 */
static const guchar unsol_plmn_changed_parcel1[] = {
	0x01, 0x00, 0x00, 0x00,	0x05, 0x00, 0x00, 0x00, 0x32, 0x00, 0x31, 0x00,
	0x34, 0x00, 0x30, 0x00, 0x31, 0x00, 0x00, 0x00
};

static const struct ril_msg unsol_plmn_changed_valid_1 = {
	.buf = (gchar *) &unsol_plmn_changed_parcel1,
	.buf_len = sizeof(unsol_plmn_changed_parcel1),
	.unsolicited = TRUE,
	.req = MTK_RIL_UNSOL_RESPONSE_PLMN_CHANGED,
	.serial_no = 0,
	.error = 0,
};

/*
 * The following hexadecimal data represents a serialized Binder parcel instance
 * containing a MTK_RIL_UNSOL_RESPONSE_PLMN_CHANGED message with no strings.
 */
static const guchar unsol_plmn_changed_parcel2[] = {
	0x00, 0x00, 0x00, 0x00
};

static const struct ril_msg unsol_plmn_changed_invalid_1 = {
	.buf = (gchar *) &unsol_plmn_changed_parcel2,
	.buf_len = sizeof(unsol_plmn_changed_parcel2),
	.unsolicited = TRUE,
	.req = MTK_RIL_UNSOL_RESPONSE_PLMN_CHANGED,
	.serial_no = 0,
	.error = 0,
};

static void test_unsol_incoming_call_indication_valid(gconstpointer data)
{
	struct unsol_call_indication *unsol;

	unsol = g_mtk_unsol_parse_incoming_call_indication(NULL,
						(struct ril_msg *) data);

	g_assert(unsol != NULL);
	g_mtk_unsol_free_call_indication(unsol);
}

static void test_unsol_registration_suspended_valid(gconstpointer data)
{
	int suspended;

	suspended = g_mtk_unsol_parse_registration_suspended(NULL,
						(struct ril_msg *) data);

	g_assert(suspended > 0);
}

static void test_unsol_plmn_changed_valid(gconstpointer data)
{
	struct parcel_str_array *plmns;

	plmns = g_mtk_unsol_parse_plmn_changed(NULL, (struct ril_msg *) data);

	g_assert(plmns != NULL);
	parcel_free_str_array(plmns);
}

static void test_unsol_plmn_changed_invalid(gconstpointer data)
{
	struct parcel_str_array *plmns;

	plmns = g_mtk_unsol_parse_plmn_changed(NULL, (struct ril_msg *) data);

	g_assert(plmns == NULL);
}

#endif	/* LITTLE_ENDIAN */

int main(int argc, char **argv)
{
	g_test_init(&argc, &argv, NULL);

/*
 * As all our architectures are little-endian except for
 * PowerPC, and the Binder wire-format differs slightly
 * depending on endian-ness, the following guards against test
 * failures when run on PowerPC.
 */
#if BYTE_ORDER == LITTLE_ENDIAN

	g_test_add_data_func("/testmtkunsol/voicecall: "
				"valid INCOMING_CALL_INDICATION Test 1",
				&unsol_incoming_call_indication_valid_1,
				test_unsol_incoming_call_indication_valid);

	g_test_add_data_func("/testmtkunsol/network: "
				"valid RESPONSE_REGISTRATION_SUSPENDED Test 1",
				&unsol_registration_suspended_valid_1,
				test_unsol_registration_suspended_valid);

	g_test_add_data_func("/testmtkunsol/fw: "
				"valid RESPONSE_PLMN_CHANGED Test 1",
				&unsol_plmn_changed_valid_1,
				test_unsol_plmn_changed_valid);

	g_test_add_data_func("/testmtkunsol/fw: "
				"invalid RESPONSE_PLMN_CHANGED Test 1",
				&unsol_plmn_changed_invalid_1,
				test_unsol_plmn_changed_invalid);

#endif	/* LITTLE_ENDIAN */

	return g_test_run();
}
