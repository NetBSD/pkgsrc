# $NetBSD: buildlink2.mk,v 1.3 2002/12/05 19:10:42 drochner Exp $

.if !defined(LESSTIF_BUILDLINK2_MK)
LESSTIF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		lesstif
BUILDLINK_DEPENDS.lesstif?=	lesstif>=0.91.4
BUILDLINK_PKGSRCDIR.lesstif?=	../../x11/lesstif

EVAL_PREFIX+=	BUILDLINK_PREFIX.lesstif=lesstif
BUILDLINK_PREFIX.lesstif_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.lesstif=	include/Dt/*
BUILDLINK_FILES.lesstif+=	include/Mrm/*
BUILDLINK_FILES.lesstif+=	include/Xm/*
BUILDLINK_FILES.lesstif+=	include/uil/*
BUILDLINK_FILES.lesstif+=	lib/libDtPrint.*
BUILDLINK_FILES.lesstif+=	lib/libMrm.*
BUILDLINK_FILES.lesstif+=	lib/libUil.*
BUILDLINK_FILES.lesstif+=	lib/libXm.*

BUILDLINK_TARGETS+=		lesstif-buildlink

lesstif-buildlink: _BUILDLINK_USE

.endif	# LESSTIF_BUILDLINK2_MK
