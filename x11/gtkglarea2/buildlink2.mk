# $NetBSD: buildlink2.mk,v 1.4 2003/12/13 00:45:26 wiz Exp $
#
# This Makefile fragment is included by packages that use gtkglarea2.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(GTKGLAREA2_BUILDLINK2_MK)
GTKGLAREA2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gtkglarea2
BUILDLINK_DEPENDS.gtkglarea2?=		gtkglarea2>=1.99.0nb2
BUILDLINK_PKGSRCDIR.gtkglarea2?=		../../x11/gtkglarea2

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtkglarea2=gtkglarea2
BUILDLINK_PREFIX.gtkglarea2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtkglarea2+=	include/gtkgl-2.0/gtkgl/gdkgl.h
BUILDLINK_FILES.gtkglarea2+=	include/gtkgl-2.0/gtkgl/gtkglarea.h
BUILDLINK_FILES.gtkglarea2+=	lib/libgtkgl-2.0.*
BUILDLINK_FILES.gtkglarea2+=	lib/pkgconfig/gtkgl-2.0.pc

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	gtkglarea2-buildlink

gtkglarea2-buildlink: _BUILDLINK_USE

.endif	# GTKGLAREA2_BUILDLINK2_MK
