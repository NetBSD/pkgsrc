# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/03 05:18:46 martti Exp $
#
# This Makefile fragment is included by packages that use xfce4-clipman-plugin.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(XFCE4_CLIPMAN_PLUGIN_BUILDLINK2_MK)
XFCE4_CLIPMAN_PLUGIN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-clipman-plugin
BUILDLINK_DEPENDS.xfce4-clipman-plugin?=		xfce4-clipman-plugin>=0.3.1
BUILDLINK_PKGSRCDIR.xfce4-clipman-plugin?=		../../x11/xfce4-clipman-plugin

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-clipman-plugin=xfce4-clipman-plugin
BUILDLINK_PREFIX.xfce4-clipman-plugin_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-clipman-plugin+=	lib/xfce4/panel-plugins/libclipman.*

.include "../../x11/xfce4-panel/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-clipman-plugin-buildlink

xfce4-clipman-plugin-buildlink: _BUILDLINK_USE

.endif	# XFCE4_CLIPMAN_PLUGIN_BUILDLINK2_MK
