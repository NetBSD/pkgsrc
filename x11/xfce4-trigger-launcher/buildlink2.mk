# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/09/26 10:59:10 martti Exp $
#
# This Makefile fragment is included by packages that use xfce4-trigger-launcher.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFCE4_TRIGGER_LAUNCHER_BUILDLINK2_MK)
XFCE4_TRIGGER_LAUNCHER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-trigger-launcher
BUILDLINK_DEPENDS.xfce4-trigger-launcher?=		xfce4-trigger-launcher>=4.0.0
BUILDLINK_PKGSRCDIR.xfce4-trigger-launcher?=		../../x11/xfce4-trigger-launcher

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-trigger-launcher=xfce4-trigger-launcher
BUILDLINK_PREFIX.xfce4-trigger-launcher_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-trigger-launcher+=	lib/xfce4/panel-plugins/libtriggerlauncher.*

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/xfce4-panel/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-trigger-launcher-buildlink

xfce4-trigger-launcher-buildlink: _BUILDLINK_USE

.endif	# XFCE4_TRIGGER_LAUNCHER_BUILDLINK2_MK
