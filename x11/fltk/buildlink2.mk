# $NetBSD: buildlink2.mk,v 1.4 2003/03/12 22:07:29 jschauma Exp $

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

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"

BUILDLINK_TARGETS+=	fltk-buildlink

fltk-buildlink: _BUILDLINK_USE

.endif	# FLTK_BUILDLINK2_MK
