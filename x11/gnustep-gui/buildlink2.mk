# $NetBSD: buildlink2.mk,v 1.10 2004/04/10 23:44:28 rh Exp $
#

.if !defined(GNUSTEP_GUI_BUILDLINK2_MK)
GNUSTEP_GUI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnustep-gui
BUILDLINK_DEPENDS.gnustep-gui?=		gnustep-gui>=0.9.2
BUILDLINK_PKGSRCDIR.gnustep-gui?=	../../x11/gnustep-gui

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnustep-gui=gnustep-gui
BUILDLINK_PREFIX.gnustep-gui_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnustep-gui+=	share/GNUstep/System/Library/Headers/AppKit/*
BUILDLINK_FILES.gnustep-gui+=	share/GNUstep/System/Library/Headers/GNUstepGUI/*
BUILDLINK_FILES.gnustep-gui+=	share/GNUstep/System/Library/Headers/gnustep/AppKit/*
BUILDLINK_FILES.gnustep-gui+=	share/GNUstep/System/Library/Libraries/libgnustep-gui.*

.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../devel/gnustep-base/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

BUILDLINK_TARGETS+=	gnustep-gui-buildlink

gnustep-gui-buildlink: _BUILDLINK_USE

.endif	# GNUSTEP_GUI_BUILDLINK2_MK
