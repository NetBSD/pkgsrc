# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/07/13 20:54:33 wiz Exp $
#
# This Makefile fragment is included by packages that use paragui.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(PARAGUI_BUILDLINK2_MK)
PARAGUI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			paragui
BUILDLINK_DEPENDS.paragui?=		paragui>=1.0.4
BUILDLINK_PKGSRCDIR.paragui?=		../../x11/paragui

EVAL_PREFIX+=	BUILDLINK_PREFIX.paragui=paragui
BUILDLINK_PREFIX.paragui_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.paragui+=	include/paragui/*
BUILDLINK_FILES.paragui+=	include/physfs.h
BUILDLINK_FILES.paragui+=	lib/libparagui-1.0.*
BUILDLINK_FILES.paragui+=	lib/libparagui.*
BUILDLINK_FILES.paragui+=	lib/pkgconfig/paragui.pc

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"

BUILDLINK_TARGETS+=	paragui-buildlink

paragui-buildlink: _BUILDLINK_USE

.endif	# PARAGUI_BUILDLINK2_MK
