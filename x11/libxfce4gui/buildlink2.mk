# $NetBSD: buildlink2.mk,v 1.2 2003/09/27 06:57:16 martti Exp $
#
# This Makefile fragment is included by packages that use libxfce4gui.
#
# This file was created automatically using createbuildlink 2.7.
#

.if !defined(LIBXFCE4GUI_BUILDLINK2_MK)
LIBXFCE4GUI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libxfce4gui
BUILDLINK_DEPENDS.libxfce4gui?=		libxfce4gui>=4.0.0
BUILDLINK_PKGSRCDIR.libxfce4gui?=		../../x11/libxfce4gui

EVAL_PREFIX+=	BUILDLINK_PREFIX.libxfce4gui=libxfce4gui
BUILDLINK_PREFIX.libxfce4gui_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/dialogs.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/gtk_style.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/gtktoxevent.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/icons.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/libnetk.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/libxfcegui4.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/netk-application.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/netk-enum-types.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/netk-marshal.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/netk-pager.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/netk-screen.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/netk-tasklist.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/netk-trayicon.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/netk-util.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/netk-window-menu.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/netk-window.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/netk-workspace.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/preview_filesel.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/session-client.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/xfce_clock.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/xfce_decorbutton.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/xfce_decortoggle.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/xfce_framebox.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/xfce_iconbutton.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/xfce_marshal.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/xfce_menubutton.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/xfce_movehandler.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/xfce_systemtray.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/xfce_togglebutton.h
BUILDLINK_FILES.libxfce4gui+=	include/xfce4/libxfcegui4/xinerama.h
BUILDLINK_FILES.libxfce4gui+=	lib/libxfcegui4.*
BUILDLINK_FILES.libxfce4gui+=	lib/pkgconfig/libxfcegui4-1.0.pc

.include "../../x11/libxfce4util/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	libxfce4gui-buildlink

libxfce4gui-buildlink: _BUILDLINK_USE

.endif	# LIBXFCE4GUI_BUILDLINK2_MK
