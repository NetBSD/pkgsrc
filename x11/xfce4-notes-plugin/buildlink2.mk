# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/03 05:20:48 martti Exp $
#
# This Makefile fragment is included by packages that use xfce4-notes-plugin.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(XFCE4_NOTES_PLUGIN_BUILDLINK2_MK)
XFCE4_NOTES_PLUGIN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-notes-plugin
BUILDLINK_DEPENDS.xfce4-notes-plugin?=		xfce4-notes-plugin>=0.9.7
BUILDLINK_PKGSRCDIR.xfce4-notes-plugin?=		../../x11/xfce4-notes-plugin

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-notes-plugin=xfce4-notes-plugin
BUILDLINK_PREFIX.xfce4-notes-plugin_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-notes-plugin+=	lib/xfce4/panel-plugins/libnotes.*

.include "../../x11/xfce4-panel/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-notes-plugin-buildlink

xfce4-notes-plugin-buildlink: _BUILDLINK_USE

.endif	# XFCE4_NOTES_PLUGIN_BUILDLINK2_MK
