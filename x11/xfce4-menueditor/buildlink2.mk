# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/26 16:33:37 martti Exp $
#
# This Makefile fragment is included by packages that use xfce4-menueditor.
#
# This file was created automatically using createbuildlink-3.0.
#

.if !defined(XFCE4_MENUEDITOR_BUILDLINK2_MK)
XFCE4_MENUEDITOR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-menueditor
BUILDLINK_DEPENDS.xfce4-menueditor?=		xfce4-menueditor>=1.0rc3
BUILDLINK_PKGSRCDIR.xfce4-menueditor?=		../../x11/xfce4-menueditor

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-menueditor=xfce4-menueditor
BUILDLINK_PREFIX.xfce4-menueditor_DEFAULT=	${X11PREFIX}

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/libxfce4gui/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-menueditor-buildlink

xfce4-menueditor-buildlink: _BUILDLINK_USE

.endif	# XFCE4_MENUEDITOR_BUILDLINK2_MK
