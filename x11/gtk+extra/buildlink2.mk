# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:30 jlam Exp $

.if !defined(GTKEXTRA_BUILDLINK2_MK)
GTKEXTRA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gtkextra
BUILDLINK_DEPENDS.gtkextra?=	gtk+extra>=0.99.17
BUILDLINK_PKGSRCDIR.gtkextra?=	../../x11/gtk+extra

EVAL_PREFIX+=		BUILDLINK_PREFIX.gtkextra=gtk+extra
BUILDLINK_PREFIX.gtkextra_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gtkextra=	include/gtkextra/*
BUILDLINK_FILES.gtkextra+=	lib/libgtkextra.*

.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	gtkextra-buildlink

gtkextra-buildlink: _BUILDLINK_USE

.endif	# GTKEXTRA_BUILDLINK2_MK
