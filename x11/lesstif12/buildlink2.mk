# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:42 jlam Exp $

.if !defined(LESSTIF12_BUILDLINK2_MK)
LESSTIF12_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		lesstif12
BUILDLINK_DEPENDS.lesstif12?=	lesstif12>=0.91.4
BUILDLINK_PKGSRCDIR.lesstif12?=	../../x11/lesstif12

EVAL_PREFIX+=			_LESSTIF12_PREFIX=lesstif12
_LESSTIF12_PREFIX_DEFAULT=	${X11PREFIX}
BUILDLINK_PREFIX.lesstif12=	${_LESSTIF12_PREFIX}/LessTif/Motif1.2
BUILDLINK_FILES.lesstif12=	include/Mrm/*
BUILDLINK_FILES.lesstif12+=	include/Xm/*
BUILDLINK_FILES.lesstif12+=	include/uil/*
BUILDLINK_FILES.lesstif12+=	lib/libMrm.*
BUILDLINK_FILES.lesstif12+=	lib/libUil.*
BUILDLINK_FILES.lesstif12+=	lib/libXm.*

BUILDLINK_TARGETS+=		lesstif12-buildlink

lesstif12-buildlink: _BUILDLINK_USE

.endif	# LESSTIF12_BUILDLINK2_MK
