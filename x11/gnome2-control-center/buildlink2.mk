# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/15 05:48:52 rh Exp $
#
# This Makefile fragment is included by packages that use gnome2-control-center.
#
# This file was created automatically using createbuildlink 2.0.
#

.if !defined(GNOME2_CONTROL_CENTER_BUILDLINK2_MK)
GNOME2_CONTROL_CENTER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome2-control-center
BUILDLINK_DEPENDS.gnome2-control-center?=	gnome2-control-center>=2.0.1.1
BUILDLINK_PKGSRCDIR.gnome2-control-center?=		../../x11/gnome2-control-center

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome2-control-center=gnome2-control-center
BUILDLINK_PREFIX.gnome2-control-center_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gnome2-control-center+=	include/gnome-window-settings-2.0/gnome-window-manager.h
BUILDLINK_FILES.gnome2-control-center+=	include/gnome-window-settings-2.0/gnome-wm-manager.h
BUILDLINK_FILES.gnome2-control-center+=	lib/bonobo/servers/GNOME_SettingsDaemon.server
BUILDLINK_FILES.gnome2-control-center+=	lib/libgnome-window-settings.*
BUILDLINK_FILES.gnome2-control-center+=	lib/pkgconfig/gnome-window-settings-2.0.pc

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/gnome-desktop/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome2-control-center-buildlink

gnome2-control-center-buildlink: _BUILDLINK_USE

.endif	# GNOME2_CONTROL_CENTER_BUILDLINK2_MK
