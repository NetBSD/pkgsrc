# $NetBSD: buildlink2.mk,v 1.3 2003/09/27 06:57:16 martti Exp $
#
# This Makefile fragment is included by packages that use xfce4-wm-themes.
#
# This file was created automatically using createbuildlink 2.7.
#

.if !defined(XFCE4_WM_THEMES_BUILDLINK2_MK)
XFCE4_WM_THEMES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-wm-themes
BUILDLINK_DEPENDS.xfce4-wm-themes?=		xfce4-wm-themes>=4.0.0
BUILDLINK_PKGSRCDIR.xfce4-wm-themes?=		../../wm/xfce4-wm-themes

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-wm-themes=xfce4-wm-themes
BUILDLINK_PREFIX.xfce4-wm-themes_DEFAULT=	${X11PREFIX}

.include "../../wm/xfce4-wm/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-wm-themes-buildlink

xfce4-wm-themes-buildlink: _BUILDLINK_USE

.endif	# XFCE4_WM_THEMES_BUILDLINK2_MK
