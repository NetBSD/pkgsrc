# $NetBSD: buildlink2.mk,v 1.3 2002/11/25 18:21:02 jlam Exp $

.if !defined(FLTK_BUILDLINK2_MK)
FLTK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		fltk
BUILDLINK_DEPENDS.fltk?=	fltk>=1.0.9
BUILDLINK_PKGSRCDIR.fltk?=	../../x11/fltk

EVAL_PREFIX+=		BUILDLINK_PREFIX.fltk=fltk
BUILDLINK_PREFIX.fltk_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.fltk=	include/FL/*
BUILDLINK_FILES.fltk+=	include/Fl/*
BUILDLINK_FILES.fltk+=	lib/libfltk.*

.include "../../graphics/Mesa/buildlink2.mk"

BUILDLINK_TARGETS+=	fltk-buildlink

fltk-buildlink: _BUILDLINK_USE

.endif	# FLTK_BUILDLINK2_MK
