# $NetBSD: buildlink2.mk,v 1.9 2004/04/10 23:46:55 rh Exp $
#

.if !defined(GNUSTEP_BACK_BUILDLINK2_MK)
GNUSTEP_BACK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnustep-back
BUILDLINK_DEPENDS.gnustep-back?=	gnustep-back>=0.9.2
BUILDLINK_PKGSRCDIR.gnustep-back?=	../../x11/gnustep-back

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnustep-back=gnustep-back
BUILDLINK_PREFIX.gnustep-back_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnustep-back=	share/GNUstep/System/Headers/gnustep/gsc/*
BUILDLINK_FILES.gnustep-back+=	share/GNUstep/System/Headers/gnustep/x11/*
BUILDLINK_FILES.gnustep-back+=	share/GNUstep/System/Headers/gnustep/xlib/*

.include "../../graphics/libart2/buildlink2.mk"
.include "../../x11/gnustep-gui/buildlink2.mk"

BUILDLINK_TARGETS+=	gnustep-back-buildlink

gnustep-back-buildlink: _BUILDLINK_USE

.endif	# GNUSTEP_BACK_BUILDLINK2_MK
