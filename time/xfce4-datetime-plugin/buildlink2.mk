# $NetBSD: buildlink2.mk,v 1.2 2003/12/13 00:45:25 wiz Exp $
#
# This Makefile fragment is included by packages that use xfce4-datetime-plugin.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(XFCE4_DATETIME_PLUGIN_BUILDLINK2_MK)
XFCE4_DATETIME_PLUGIN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-datetime-plugin
BUILDLINK_DEPENDS.xfce4-datetime-plugin?=		xfce4-datetime-plugin>=0.2nb1
BUILDLINK_PKGSRCDIR.xfce4-datetime-plugin?=		../../time/xfce4-datetime-plugin

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-datetime-plugin=xfce4-datetime-plugin
BUILDLINK_PREFIX.xfce4-datetime-plugin_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-datetime-plugin+=	lib/xfce4/panel-plugins/libdatetime.*

.include "../../x11/xfce4-panel/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-datetime-plugin-buildlink

xfce4-datetime-plugin-buildlink: _BUILDLINK_USE

.endif	# XFCE4_DATETIME_PLUGIN_BUILDLINK2_MK
