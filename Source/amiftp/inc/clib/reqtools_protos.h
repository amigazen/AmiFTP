/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright 2026 amigazen project
 *
 * C prototypes for reqtools (from ReqTools 2.5; original (C) Nico François, Magnus Holmgren).
 */

#ifndef CLIB_REQTOOLS_PROTOS_H
#define CLIB_REQTOOLS_PROTOS_H
/*
**	$Filename: clib/reqtools_protos.h $
**	$Release: 2.5 $
**	$Revision: 38.11 $
**
**	C prototypes. For use with 32 bit integers only.
**
**	(C) Copyright 1991-1994 Nico François
**		      1995-1996 Magnus Holmgren
**	    All Rights Reserved
**
*/

#ifndef LIBRARIES_REQTOOLS_H
#include <libraries/reqtools.h>
#endif

APTR  rtAllocRequestA (ULONG, struct TagItem *);
void  rtFreeRequest (APTR);
void  rtFreeReqBuffer (APTR);
LONG  rtChangeReqAttrA (APTR, struct TagItem *);
APTR  rtFileRequestA(struct rtFileRequester *,char *,char *,struct TagItem *);
void  rtFreeFileList (struct rtFileList *);
ULONG rtEZRequestA (char *,char *,struct rtReqInfo *,APTR,struct TagItem *);
ULONG rtGetStringA (UBYTE *,ULONG,char *,struct rtReqInfo *,struct TagItem *);
ULONG rtGetLongA (ULONG *, char *, struct rtReqInfo *, struct TagItem *);
ULONG rtFontRequestA (struct rtFontRequester *, char *, struct TagItem *);
LONG  rtPaletteRequestA (char *, struct rtReqInfo *, struct TagItem *);
ULONG rtReqHandlerA (struct rtHandlerInfo *, ULONG, struct TagItem *);
void  rtSetWaitPointer (struct Window *);
ULONG rtGetVScreenSize (struct Screen *, ULONG *, ULONG *);
void  rtSetReqPosition (ULONG, struct NewWindow *,
                        struct Screen *, struct Window *);
void  rtSpread (ULONG *, ULONG *, ULONG, ULONG, ULONG, ULONG);
void  rtScreenToFrontSafely (struct Screen *);
ULONG rtScreenModeRequestA (struct rtScreenModeRequester *,
                            char *, struct TagItem *);
void  rtCloseWindowSafely (struct Window *);
APTR  rtLockWindow (struct Window *);
void  rtUnlockWindow (struct Window *, APTR);

struct ReqToolsPrefs *rtLockPrefs (void);
void rtUnlockPrefs (void);

APTR  rtAllocRequest (ULONG, Tag,...);
LONG  rtChangeReqAttr (APTR, Tag,...);
APTR  rtFileRequest (struct rtFileRequester *, char *, char *, Tag,...);
ULONG rtEZRequest (char *, char *, struct rtReqInfo *, struct TagItem *,...);
ULONG rtEZRequestTags (char *, char *, struct rtReqInfo *, APTR, Tag,...);
ULONG rtGetString (UBYTE *, ULONG, char *, struct rtReqInfo *, Tag,...);
ULONG rtGetLong (ULONG *, char *, struct rtReqInfo *, Tag,...);
ULONG rtFontRequest (struct rtFontRequester *, char *, Tag,...);
LONG  rtPaletteRequest (char *, struct rtReqInfo *, Tag,...);
ULONG rtReqHandler (struct rtHandlerInfo *, ULONG, Tag,...);
ULONG rtScreenModeRequest (struct rtScreenModeRequester *, char *, Tag,...);

#endif /* CLIB_REQTOOLS_PROTOS_H */
