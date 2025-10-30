/************************************************************************
 * NASA Docket No. GSC-18,917-1, and identified as “CFS Data Storage
 * (DS) application version 2.6.1”
 *
 * Copyright (c) 2021 United States Government as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ************************************************************************/

/**
 * @file
 *   CFS Data Storage (DS) sample packet filter table
 *
 * @note
 *   This source file creates a sample table that stores packets using
 *   several different destination storage files.  Some packets have
 *   one filter that is set to store every packet in one file and
 *   another filter that will store every other packet in a second
 *   file.  Also, some filters are disabled and thus will not store
 *   any packets.  There is no real purpose to this particular set of
 *   filters other than to provide an example of how various fields
 *   in the table might be used.
 */

#include "cfe.h"
#include "cfe_tbl_filedef.h"
#include "ds_platform_cfg.h"
#include "ds_extern_typedefs.h"
#include "ds_msg.h"
#include "cfe_msgids.h" //bc

/*
** Note: Include header files that define the message ID's for the
**       mission specific list of packets that need to be stored.
*/
#include "cfe_msgids.h"
#include "ds_msgids.h"

/* #include "ci_lab_msgids.h"  */
/* #include "to_lab_msgids.h"  */

/* #include "cs_msgids.h"  */
/* #include "ds_msgids.h"  */
/* #include "fm_msgids.h"  */
/* #include "hk_msgids.h"  */
/* #include "hs_msgids.h"  */
/* #include "lc_msgids.h"  */
/* #include "md_msgids.h"  */
/* #include "mm_msgids.h"  */
/* #include "sc_msgids.h"  */
/* #include "sch_msgids.h" */

/*
** Note: It is suggested that missions pre-define their file table
**       index numbers in a public header file to be included by
**       both the packet filter table source file and the destination
**       file table source file. Common definitions may also be used
**       when creating command database entries that require file
**       index numbers for command arguments.
*/
#define FILE_ALL_EVENTS 0

#define FILE_ALL_APP_HK_PKTS  1
#define FILE_ALL_APP_TLM_PKTS 2

#define FILE_ALL_HW_TLM_PKTS 3

#define FILE_CFE_APP_HK_PKTS  4
#define FILE_CFE_APP_TLM_PKTS 5

/*
** Sample packet filter table data
*/
DS_FilterTable_t DS_FilterTable = {
    /* .Descriptor = */ "Sample filter table data",
    /* .Packet     = */
    {/* Packet Index 000 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_APP_HK_PKTS, DS_BY_COUNT, 1, 1, 0},
       {FILE_CFE_APP_HK_PKTS, DS_BY_COUNT, 1, 2, 0},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 001 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_APP_HK_PKTS, DS_BY_COUNT, 1, 1, 0},
       {FILE_CFE_APP_HK_PKTS, DS_BY_COUNT, 1, 2, 1},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 002 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_APP_HK_PKTS, DS_BY_COUNT, 1, 2, 0},
       {FILE_CFE_APP_HK_PKTS, DS_BY_COUNT, 1, 1, 0},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 003 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_APP_HK_PKTS, DS_BY_COUNT, 1, 2, 0},
       {FILE_CFE_APP_HK_PKTS, DS_BY_COUNT, 1, 1, 0},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 004 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_APP_HK_PKTS, DS_BY_COUNT, 1, 2, 1},
       {FILE_CFE_APP_HK_PKTS, DS_BY_COUNT, 1, 1, 0},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 005 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_APP_TLM_PKTS, DS_BY_COUNT, 1, 2, 0},
       {FILE_CFE_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 006 */
     //bc CFE_SB_MSGID_WRAP_VALUE(CFE_EVS_LONG_EVENT_MSG_MID)
     {/* .MessageID = */  CFE_SB_MSGID_WRAP_VALUE((uint16)CFE_PLATFORM_TLM_TOPICID_TO_MID(CFE_MISSION_EVS_LONG_EVENT_MSG_TOPICID)), //bc
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_EVENTS, DS_BY_COUNT, 1, 1, 0},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 007 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {FILE_CFE_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 008 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {FILE_CFE_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 009 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {FILE_CFE_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 010 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {FILE_CFE_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 011 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {FILE_CFE_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 012 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {FILE_CFE_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 013 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {FILE_ALL_APP_HK_PKTS, DS_BY_COUNT, 1, 1, 0},
       {FILE_ALL_APP_TLM_PKTS, DS_BY_COUNT, 1, 1, 0},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 014 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}},
     /* Packet Index 015 */
     {/* .MessageID = */ CFE_SB_MSGID_RESERVED,
      /* .Filter    = */
      {/* File table index, filter type, N, X, O */
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED},
       {DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED, DS_UNUSED}}}}};

/*
** Sample packet filter table header
*/
CFE_TBL_FILEDEF(DS_FilterTable, DS.FILTER_TBL, DS Packet Filter Table, ds_filter_tbl.tbl)

/************************/
/*  End of File Comment */
/************************/
