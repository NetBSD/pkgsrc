# $NetBSD: buildlink2.mk,v 1.2 2003/09/27 06:57:16 martti Exp $
#
# This Makefile fragment is included by packages that use xfce4-panel.
#
# This file was created automatically using createbuildlink 2.7.
#

.if !defined(XFCE4_PANEL_BUILDLINK2_MK)
XFCE4_PANEL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-panel
BUILDLINK_DEPENDS.xfce4-panel?=		xfce4-panel>=4.0.0
BUILDLINK_PKGSRCDIR.xfce4-panel?=		../../x11/xfce4-panel

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-panel=xfce4-panel
BUILDLINK_PREFIX.xfce4-panel_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-panel+=	include/xfce4/panel/controls.h
BUILDLINK_FILES.xfce4-panel+=	include/xfce4/panel/global.h
BUILDLINK_FILES.xfce4-panel+=	include/xfce4/panel/icons.h
BUILDLINK_FILES.xfce4-panel+=	include/xfce4/panel/item.h
BUILDLINK_FILES.xfce4-panel+=	include/xfce4/panel/item_dialog.h
BUILDLINK_FILES.xfce4-panel+=	include/xfce4/panel/main.h
BUILDLINK_FILES.xfce4-panel+=	include/xfce4/panel/panel.h
BUILDLINK_FILES.xfce4-panel+=	include/xfce4/panel/plugins.h
BUILDLINK_FILES.xfce4-panel+=	include/xfce4/panel/xfce.h
BUILDLINK_FILES.xfce4-panel+=	include/xfce4/panel/xfce_support.h
BUILDLINK_FILES.xfce4-panel+=	lib/pkgconfig/xfce4-panel-1.0.pc
BUILDLINK_FILES.xfce4-panel+=	lib/xfce4/mcs-plugins/libxfce4settings.*
BUILDLINK_FILES.xfce4-panel+=	lib/xfce4/panel-plugins/libclock.*
BUILDLINK_FILES.xfce4-panel+=	lib/xfce4/panel-plugins/libmailcheck.*
BUILDLINK_FILES.xfce4-panel+=	lib/xfce4/panel-plugins/libpager.*
BUILDLINK_FILES.xfce4-panel+=	lib/xfce4/panel-plugins/libseparator.*
BUILDLINK_FILES.xfce4-panel+=	lib/xfce4/panel-plugins/libswitcher.*
BUILDLINK_FILES.xfce4-panel+=	lib/xfce4/panel-plugins/libsystembuttons.*

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-panel-buildlink

xfce4-panel-buildlink: _BUILDLINK_USE

.endif	# XFCE4_PANEL_BUILDLINK2_MK
