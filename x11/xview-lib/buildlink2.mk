# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:56 jlam Exp $

.if !defined(XVIEW_BUILDLINK2_MK)
XVIEW_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		xview
BUILDLINK_PKGBASE.xview?=	xview-lib
BUILDLINK_DEPENDS.xview?=	xview-lib>=3.2.1
BUILDLINK_PKGSRCDIR.xview?=	../../x11/xview-lib

EVAL_PREFIX+=			BUILDLINK_PREFIX.xview=xview-lib
BUILDLINK_PREFIX.xview_DEFAULT=	${X11PREFIX}

BUILDLINK_FILES.xview=	include/bitmaps/*
BUILDLINK_FILES.xview+=	include/images/*
BUILDLINK_FILES.xview+=	include/olgx/*
BUILDLINK_FILES.xview+=	include/olgx_private/*
BUILDLINK_FILES.xview+=	include/pixrect/*
BUILDLINK_FILES.xview+=	include/xview/*
BUILDLINK_FILES.xview+=	include/xview_private/*
BUILDLINK_FILES.xview+=	lib/libolgx.*
BUILDLINK_FILES.xview+=	lib/libxview.*

BUILDLINK_TARGETS+=	xview-buildlink

xview-buildlink: _BUILDLINK_USE

.endif	# XVIEW_BUILDLINK2_MK
