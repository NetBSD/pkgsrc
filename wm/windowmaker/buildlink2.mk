# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:46 jlam Exp $

.if !defined(WINDOWMAKER_BUILDLINK2_MK)
WINDOWMAKER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			windowmaker
BUILDLINK_DEPENDS.windowmaker?=		windowmaker>=0.80.0nb1
BUILDLINK_PKGSRCDIR.windowmaker?=	../../wm/windowmaker

EVAL_PREFIX+=			BUILDLINK_PREFIX.windowmaker=windowmaker
BUILDLINK_PREFIX.windowmaker_DEFAULT=	${X11PREFIX}

BUILDLINK_FILES.windowmaker=	include/WINGs/*
BUILDLINK_FILES.windowmaker+=	include/WMaker.h
BUILDLINK_FILES.windowmaker+=	include/wraster.h
BUILDLINK_FILES.windowmaker+=	lib/libExtraWINGs.a
BUILDLINK_FILES.windowmaker+=	lib/libWINGs.a
BUILDLINK_FILES.windowmaker+=	lib/libWMaker.a
BUILDLINK_FILES.windowmaker+=	lib/libWUtil.a
BUILDLINK_FILES.windowmaker+=	lib/libwraster.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/hermes/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

BUILDLINK_TARGETS+=	windowmaker-buildlink

windowmaker-buildlink: _BUILDLINK_USE

.endif	# WINDOWMAKER_BUILDLINK2_MK
