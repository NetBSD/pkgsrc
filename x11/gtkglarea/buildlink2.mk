# $NetBSD: buildlink2.mk,v 1.4 2003/05/02 11:57:08 wiz Exp $

.if !defined(GTKGLAREA_BUILDLINK2_MK)
GTKGLAREA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gtkglarea
BUILDLINK_DEPENDS.gtkglarea?=		gtkglarea>=1.2.2nb2
BUILDLINK_PKGSRCDIR.gtkglarea?=		../../x11/gtkglarea

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtkglarea=gtkglarea
BUILDLINK_PREFIX.gtkglarea_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gtkglarea+=	include/gtkgl/*
BUILDLINK_FILES.gtkglarea+=	lib/libgtkgl.*

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	gtkglarea-buildlink

gtkglarea-buildlink: _BUILDLINK_USE

.endif	# GTKGLAREA_BUILDLINK2_MK
