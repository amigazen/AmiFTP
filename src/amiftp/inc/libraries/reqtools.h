/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright 2026 amigazen project
 *
 * reqtools.library definitions (from ReqTools 2.5; original (C) Nico François, Magnus Holmgren).
 */

#ifndef LIBRARIES_REQTOOLS_H
#define LIBRARIES_REQTOOLS_H
/*
**	$Filename: libraries/reqtools.h $
**	$Release: 2.5 $
**	$Revision: 38.13 $
**
**	reqtools.library definitions
**
**	(C) Copyright 1991-1994 Nico François
**	              1995-1996 Magnus Homgren
**	All Rights Reserved
**
*/

#ifndef	EXEC_TYPES_H
#include <exec/types.h>
#endif	/* EXEC_TYPES_H */

#ifndef	EXEC_LISTS_H
#include <exec/lists.h>
#endif	/* EXEC_LISTS_H */

#ifndef	EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif	/* EXEC_LIBRARIES_H */

#ifndef	EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif	/* EXEC_SEMAPHORES_H */

#ifndef LIBRARIES_DOS_H
#include <libraries/dos.h>
#endif  /* LIBRARIES_DOS_H */

#ifndef LIBRARIES_DOSEXTENS_H
#include <libraries/dosextens.h>
#endif  /* LIBRARIES_DOSEXTENS_H */

#ifndef LIBRARIES_DISKFONT_H
#include <libraries/diskfont.h>
#endif  /* LIBRARIES_DISKFONT_H */

#ifndef	GRAPHICS_TEXT_H
#include <graphics/text.h>
#endif	/* GRAPHICS_TEXT_H */

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif	/* UTILITY_TAGITEM_H */

#define	REQTOOLSNAME		 "reqtools.library"
#define	REQTOOLSVERSION		 38L

/***********************
*                      *
*     Preferences      *
*                      *
***********************/

#define RTPREF_FILEREQ		 0L
#define RTPREF_FONTREQ		 1L
#define RTPREF_PALETTEREQ	 2L
#define RTPREF_SCREENMODEREQ	 3L
#define RTPREF_VOLUMEREQ	 4L
#define RTPREF_OTHERREQ		 5L
#define RTPREF_NR_OF_REQ	 6L

struct ReqDefaults {
   ULONG Size;
   ULONG ReqPos;
   UWORD LeftOffset;
   UWORD TopOffset;
	UWORD MinEntries;
	UWORD MaxEntries;
   };

struct ReqToolsPrefs {
   ULONG PrefsSize;
   struct SignalSemaphore PrefsSemaphore;
   ULONG Flags;
   struct ReqDefaults ReqDefaults[RTPREF_NR_OF_REQ];
   };

#define RTPREFS_SIZE \
   (sizeof (struct ReqToolsPrefs) - sizeof (struct SignalSemaphore) - 4)

#define RTPRB_DIRSFIRST		 0L
#define RTPRF_DIRSFIRST		 (1L<<RTPRB_DIRSFIRST)
#define RTPRB_DIRSMIXED		 1L
#define RTPRF_DIRSMIXED		 (1L<<RTPRB_DIRSMIXED)
#define RTPRB_IMMSORT		 2L
#define RTPRF_IMMSORT		 (1L<<RTPRB_IMMSORT)
#define RTPRB_NOSCRTOFRONT	 3L
#define RTPRF_NOSCRTOFRONT	 (1L<<RTPRB_NOSCRTOFRONT)
#define RTPRB_NOLED		 4L
#define RTPRF_NOLED		 (1L<<RTPRB_NOLED)
#define RTPRB_DEFAULTFONT	 5L
#define RTPRF_DEFAULTFONT	 (1L<<RTPRB_DEFAULTFONT)
#define RTPRB_DOWHEEL		 6L
#define RTPRF_DOWHEEL		 (1L<<RTPRB_DOWHEEL)
#define RTPRB_FKEYS		 7L
#define RTPRF_FKEYS		 (1L<<RTPRB_FKEYS)
#define RTPRB_FANCYWHEEL	 8L
#define RTPRF_FANCYWHEEL	 (1L<<RTPRB_FANCYWHEEL)
#define RTPRB_MMBPARENT		 9L
#define RTPRF_MMBPARENT		 (1L<<RTPRB_MMBPARENT)

/***********************
*     Library Base     *
***********************/

struct ReqToolsBase {
   struct Library LibNode;
   UBYTE RTFlags;
   UBYTE pad[3];
   BPTR SegList;
   struct IntuitionBase *IntuitionBase;
   struct GfxBase *GfxBase;
   struct DosLibrary *DOSBase;
   struct Library *GadToolsBase;
   struct Library *UtilityBase;
   UWORD RealOpenCnt;
   UWORD AvailFontsLock;
   struct AvailFontsHeader *AvailFontsHeader;
   ULONG FontsAssignType;
   BPTR FontsAssignLock;
   struct AssignList *FontsAssignList;
   struct ReqToolsPrefs ReqToolsPrefs;
   UWORD prefspad;
   };

#define RT_FILEREQ		 0L
#define RT_REQINFO		 1L
#define RT_FONTREQ		 2L
#define RT_SCREENMODEREQ	 3L

/***********************
*    File requester    *
***********************/

struct rtFileRequester {
   ULONG ReqPos;
   UWORD LeftOffset;
   UWORD TopOffset;
   ULONG Flags;
   struct Hook *Hook;
   char  *Dir;
   char  *MatchPat;
   struct TextFont *DefaultFont;
   ULONG WaitPointer;
   ULONG LockWindow;
   ULONG ShareIDCMP;
   struct Hook *IntuiMsgFunc;
   UWORD reserved1;
   UWORD reserved2;
   UWORD reserved3;
   UWORD ReqHeight;
   };

struct rtFileList {
   struct rtFileList *Next;
   ULONG StrLen;
   char *Name;
   };

struct rtVolumeEntry {
   ULONG Type;
   char *Name;
   };

/***********************
*    Font requester    *
***********************/

struct rtFontRequester {
   ULONG ReqPos;
   UWORD LeftOffset;
   UWORD TopOffset;
   ULONG Flags;
   struct Hook *Hook;
   struct TextAttr Attr;
   struct TextFont *DefaultFont;
   ULONG WaitPointer;
   ULONG LockWindow;
   ULONG ShareIDCMP;
   struct Hook *IntuiMsgFunc;
   UWORD reserved1;
   UWORD reserved2;
   UWORD reserved3;
   UWORD ReqHeight;
   };

/*************************
*  ScreenMode requester  *
*************************/

struct rtScreenModeRequester {
   ULONG ReqPos;
   UWORD LeftOffset;
   UWORD TopOffset;
   ULONG Flags;
   ULONG private1;
   ULONG DisplayID;
   UWORD DisplayWidth;
   UWORD DisplayHeight;
   struct TextFont *DefaultFont;
   ULONG WaitPointer;
   ULONG LockWindow;
   ULONG ShareIDCMP;
   struct Hook *IntuiMsgFunc;
   UWORD reserved1;
   UWORD reserved2;
   UWORD reserved3;
   UWORD ReqHeight;
   UWORD DisplayDepth;
   UWORD OverscanType;
   ULONG AutoScroll;
   };

/***********************
*    Requester Info    *
***********************/

struct rtReqInfo {
   ULONG ReqPos;
   UWORD LeftOffset;
   UWORD TopOffset;
   ULONG Width;
   char *ReqTitle;
   ULONG Flags;
   struct TextFont *DefaultFont;
   ULONG WaitPointer;
   ULONG LockWindow;
   ULONG ShareIDCMP;
   struct Hook *IntuiMsgFunc;
   };

/***********************
*     Handler Info     *
***********************/

struct rtHandlerInfo {
   ULONG private1;
   ULONG WaitMask;
   ULONG DoNotWait;
   };

#define CALL_HANDLER		 (ULONG)0x80000000

/*************************************
*                TAGS                *
*************************************/

#define RT_TagBase		 TAG_USER

#define RT_Window		 (RT_TagBase+1)
#define RT_IDCMPFlags		 (RT_TagBase+2)
#define RT_ReqPos		 (RT_TagBase+3)
#define RT_LeftOffset		 (RT_TagBase+4)
#define RT_TopOffset		 (RT_TagBase+5)
#define RT_PubScrName		 (RT_TagBase+6)
#define RT_Screen		 (RT_TagBase+7)
#define RT_ReqHandler		 (RT_TagBase+8)
#define RT_DefaultFont		 (RT_TagBase+9)
#define RT_WaitPointer		 (RT_TagBase+10)
#define RT_Underscore		 (RT_TagBase+11)
#define RT_ShareIDCMP		 (RT_TagBase+12)
#define RT_LockWindow		 (RT_TagBase+13)
#define RT_ScreenToFront	 (RT_TagBase+14)
#define RT_TextAttr		 (RT_TagBase+15)
#define RT_IntuiMsgFunc		 (RT_TagBase+16)
#define RT_Locale		 (RT_TagBase+17)

#define RTEZ_ReqTitle		 (RT_TagBase+20)
#define RTEZ_Flags		 (RT_TagBase+22)
#define RTEZ_DefaultResponse	 (RT_TagBase+23)

#define RTGL_Min		 (RT_TagBase+30)
#define RTGL_Max		 (RT_TagBase+31)
#define RTGL_Width		 (RT_TagBase+32)
#define RTGL_ShowDefault	 (RT_TagBase+33)
#define RTGL_GadFmt 		 (RT_TagBase+34)
#define RTGL_GadFmtArgs		 (RT_TagBase+35)
#define RTGL_Invisible		 (RT_TagBase+36)
#define RTGL_BackFill		 (RT_TagBase+37)
#define RTGL_TextFmt		 (RT_TagBase+38)
#define RTGL_TextFmtArgs	 (RT_TagBase+39)
#define RTGL_CenterText		 (RT_TagBase+100)
#define RTGL_Flags		 RTEZ_Flags

#define RTGS_Width		 RTGL_Width
#define RTGS_AllowEmpty		 (RT_TagBase+80)
#define RTGS_GadFmt 		 RTGL_GadFmt
#define RTGS_GadFmtArgs		 RTGL_GadFmtArgs
#define RTGS_Invisible		 RTGL_Invisible
#define RTGS_BackFill		 RTGL_BackFill
#define RTGS_TextFmt		 RTGL_TextFmt
#define RTGS_TextFmtArgs	 RTGL_TextFmtArgs
#define RTGS_CenterText		 RTGL_CenterText
#define RTGS_Flags		 RTEZ_Flags

#define RTFI_Flags		 (RT_TagBase+40)
#define RTFI_Height		 (RT_TagBase+41)
#define RTFI_OkText		 (RT_TagBase+42)
#define RTFI_VolumeRequest	 (RT_TagBase+43)
#define RTFI_FilterFunc		 (RT_TagBase+44)
#define RTFI_AllowEmpty		 (RT_TagBase+45)

#define RTFO_Flags		 RTFI_Flags
#define RTFO_Height		 RTFI_Height
#define RTFO_OkText		 RTFI_OkText
#define RTFO_SampleHeight	 (RT_TagBase+60)
#define RTFO_MinHeight		 (RT_TagBase+61)
#define RTFO_MaxHeight		 (RT_TagBase+62)
#define RTFO_FilterFunc		 RTFI_FilterFunc

#define RTSC_Flags		 RTFI_Flags
#define RTSC_Height		 RTFI_Height
#define RTSC_OkText		 RTFI_OkText
#define RTSC_PropertyFlags	 (RT_TagBase+90)
#define RTSC_PropertyMask	 (RT_TagBase+91)
#define RTSC_MinWidth		 (RT_TagBase+92)
#define RTSC_MaxWidth		 (RT_TagBase+93)
#define RTSC_MinHeight		 (RT_TagBase+94)
#define RTSC_MaxHeight		 (RT_TagBase+95)
#define RTSC_MinDepth		 (RT_TagBase+96)
#define RTSC_MaxDepth		 (RT_TagBase+97)
#define RTSC_FilterFunc		 RTFI_FilterFunc

#define RTFI_Dir		 (RT_TagBase+50)
#define RTFI_MatchPat		 (RT_TagBase+51)
#define RTFI_AddEntry		 (RT_TagBase+52)
#define RTFI_RemoveEntry	 (RT_TagBase+53)
#define RTFO_FontName		 (RT_TagBase+63)
#define RTFO_FontHeight		 (RT_TagBase+64)
#define RTFO_FontStyle		 (RT_TagBase+65)
#define RTFO_FontFlags		 (RT_TagBase+66)
#define RTSC_ModeFromScreen	 (RT_TagBase+80)
#define RTSC_DisplayID		 (RT_TagBase+81)
#define RTSC_DisplayWidth	 (RT_TagBase+82)
#define RTSC_DisplayHeight	 (RT_TagBase+83)
#define RTSC_DisplayDepth	 (RT_TagBase+84)
#define RTSC_OverscanType	 (RT_TagBase+85)
#define RTSC_AutoScroll		 (RT_TagBase+86)

#define RTPA_Color		 (RT_TagBase+70)
#define RTRH_EndRequest		 (RT_TagBase+60)

#define REQPOS_POINTER		 0L
#define REQPOS_CENTERWIN	 1L
#define REQPOS_CENTERSCR	 2L
#define REQPOS_TOPLEFTWIN	 3L
#define REQPOS_TOPLEFTSCR	 4L

#define REQ_CANCEL		 0L
#define REQ_OK			 1L

#define FREQB_NOBUFFER		 2L
#define FREQF_NOBUFFER		 (1L<<FREQB_NOBUFFER)

#define FREQB_MULTISELECT	 0L
#define FREQF_MULTISELECT	 (1L<<FREQB_MULTISELECT)
#define FREQB_SAVE		 1L
#define FREQF_SAVE		 (1L<<FREQB_SAVE)
#define FREQB_NOFILES		 3L
#define FREQF_NOFILES		 (1L<<FREQB_NOFILES)
#define FREQB_PATGAD		 4L
#define FREQF_PATGAD		 (1L<<FREQB_PATGAD)
#define FREQB_SELECTDIRS	 12L
#define FREQF_SELECTDIRS	 (1L<<FREQB_SELECTDIRS)

#define FREQB_FIXEDWIDTH	 5L
#define FREQF_FIXEDWIDTH	 (1L<<FREQB_FIXEDWIDTH)
#define FREQB_COLORFONTS	 6L
#define FREQF_COLORFONTS	 (1L<<FREQB_COLORFONTS)
#define FREQB_CHANGEPALETTE	 7L
#define FREQF_CHANGEPALETTE	 (1L<<FREQB_CHANGEPALETTE)
#define FREQB_LEAVEPALETTE	 8L
#define FREQF_LEAVEPALETTE	 (1L<<FREQB_LEAVEPALETTE)
#define FREQB_SCALE		 9L
#define FREQF_SCALE		 (1L<<FREQB_SCALE)
#define FREQB_STYLE		 10L
#define FREQF_STYLE		 (1L<<FREQB_STYLE)

#define SCREQB_SIZEGADS		 13L
#define SCREQF_SIZEGADS		 (1L<<SCREQB_SIZEGADS)
#define SCREQB_DEPTHGAD		 14L
#define SCREQF_DEPTHGAD		 (1L<<SCREQB_DEPTHGAD)
#define SCREQB_NONSTDMODES	 15L
#define SCREQF_NONSTDMODES	 (1L<<SCREQB_NONSTDMODES)
#define SCREQB_GUIMODES		 16L
#define SCREQF_GUIMODES		 (1L<<SCREQB_GUIMODES)
#define SCREQB_AUTOSCROLLGAD	 18L
#define SCREQF_AUTOSCROLLGAD	 (1L<<SCREQB_AUTOSCROLLGAD)
#define SCREQB_OVERSCANGAD	 19L
#define SCREQF_OVERSCANGAD	 (1L<<SCREQB_OVERSCANGAD)

#define EZREQB_NORETURNKEY	 0L
#define EZREQF_NORETURNKEY	 (1L<<EZREQB_NORETURNKEY)
#define EZREQB_LAMIGAQUAL	 1L
#define EZREQF_LAMIGAQUAL	 (1L<<EZREQB_LAMIGAQUAL)
#define EZREQB_CENTERTEXT	 2L
#define EZREQF_CENTERTEXT	 (1L<<EZREQB_CENTERTEXT)

#define GLREQB_CENTERTEXT	 EZREQB_CENTERTEXT
#define GLREQF_CENTERTEXT	 EZREQF_CENTERTEXT
#define GLREQB_HIGHLIGHTTEXT	 3L
#define GLREQF_HIGHLIGHTTEXT	 (1L<<GLREQB_HIGHLIGHTTEXT)

#define GSREQB_CENTERTEXT	 EZREQB_CENTERTEXT
#define GSREQF_CENTERTEXT	 EZREQF_CENTERTEXT
#define GSREQB_HIGHLIGHTTEXT	 GLREQB_HIGHLIGHTTEXT
#define GSREQF_HIGHLIGHTTEXT	 GLREQF_HIGHLIGHTTEXT

#define VREQB_NOASSIGNS		 0L
#define VREQF_NOASSIGNS		 (1L<<VREQB_NOASSIGNS)
#define VREQB_NODISKS		 1L
#define VREQF_NODISKS		 (1L<<VREQB_NODISKS)
#define VREQB_ALLDISKS		 2L
#define VREQF_ALLDISKS		 (1L<<VREQB_ALLDISKS)

#endif /* LIBRARIES_REQTOOLS_H */
