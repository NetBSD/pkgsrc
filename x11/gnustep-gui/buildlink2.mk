# $NetBSD: buildlink2.mk,v 1.5 2003/05/02 11:57:05 wiz Exp $
#

.if !defined(GNUSTEP_GUI_BUILDLINK2_MK)
GNUSTEP_GUI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnustep-gui
BUILDLINK_DEPENDS.gnustep-gui?=		gnustep-gui>=0.8.5nb1
BUILDLINK_PKGSRCDIR.gnustep-gui?=	../../x11/gnustep-gui

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnustep-gui=gnustep-gui
BUILDLINK_PREFIX.gnustep-gui_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnustep-gui=	share/GNUstep/System/Headers/AppKit/*
BUILDLINK_FILES.gnustep-gui+=	share/GNUstep/System/Headers/gnustep/AppKit/*
BUILDLINK_FILES.gnustep-gui+=	share/GNUstep/System/Libraries/${GNUSTEP_HOST_CPU}/${GNUSTEP_HOST_OS}/gnu-gnu-gnu/libgnustep-gui.*

.include "../../devel/gnustep-base/buildlink2.mk"
.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

BUILDLINK_TARGETS+=	gnustep-gui-buildlink

gnustep-gui-buildlink: _BUILDLINK_USE

.endif	# GNUSTEP_GUI_BUILDLINK2_MK
