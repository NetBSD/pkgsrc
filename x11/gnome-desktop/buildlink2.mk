# $NetBSD: buildlink2.mk,v 1.11 2003/12/14 22:42:15 jmmv Exp $
#
# This Makefile fragment is included by packages that use gnome-desktop.
#
# This file was created automatically using createbuildlink 2.0.
#

.if !defined(GNOME_DESKTOP_BUILDLINK2_MK)
GNOME_DESKTOP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-desktop
BUILDLINK_DEPENDS.gnome-desktop?=	gnome-desktop>=2.4.1.1
BUILDLINK_PKGSRCDIR.gnome-desktop?=	../../x11/gnome-desktop

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-desktop=gnome-desktop
BUILDLINK_PREFIX.gnome-desktop_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gnome-desktop+=	include/gnome-desktop-2.0/libgnome/*
BUILDLINK_FILES.gnome-desktop+=	include/gnome-desktop-2.0/libgnomeui/*
BUILDLINK_FILES.gnome-desktop+=	lib/libgnome-desktop-2.*

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../graphics/gnome2-pixmaps/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-desktop-buildlink

gnome-desktop-buildlink: _BUILDLINK_USE

.endif	# GNOME_DESKTOP_BUILDLINK2_MK
