# $NetBSD: buildlink2.mk,v 1.1 2003/08/12 20:10:34 seb Exp $
#
# This Makefile fragment is included by packages that use XmHTML.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XMHTML_BUILDLINK2_MK)
XMHTML_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			XmHTML
BUILDLINK_DEPENDS.XmHTML?=		XmHTML>=1.1.7nb2
BUILDLINK_PKGSRCDIR.XmHTML?=		../../x11/XmHTML

EVAL_PREFIX+=	BUILDLINK_PREFIX.XmHTML=XmHTML
BUILDLINK_PREFIX.XmHTML_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.XmHTML+=	include/XmHTML/Balloon.h
BUILDLINK_FILES.XmHTML+=	include/XmHTML/BalloonP.h
BUILDLINK_FILES.XmHTML+=	include/XmHTML/HTML.h
BUILDLINK_FILES.XmHTML+=	include/XmHTML/HTMLStrings.h
BUILDLINK_FILES.XmHTML+=	include/XmHTML/XCC.h
BUILDLINK_FILES.XmHTML+=	include/XmHTML/XCCP.h
BUILDLINK_FILES.XmHTML+=	include/XmHTML/XmHTML.h
BUILDLINK_FILES.XmHTML+=	include/XmHTML/XmHTMLP.h
BUILDLINK_FILES.XmHTML+=	include/XmHTML/XmHTMLfuncs.h
BUILDLINK_FILES.XmHTML+=	include/XmHTML/debug_menu.h
BUILDLINK_FILES.XmHTML+=	include/XmHTML/resources.h
BUILDLINK_FILES.XmHTML+=	include/XmHTML/tka.h
BUILDLINK_FILES.XmHTML+=	include/XmHTML/toolkit.h
BUILDLINK_FILES.XmHTML+=	lib/libXmHTML.*

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

BUILDLINK_TARGETS+=	XmHTML-buildlink

XmHTML-buildlink: _BUILDLINK_USE

.endif	# XMHTML_BUILDLINK2_MK
