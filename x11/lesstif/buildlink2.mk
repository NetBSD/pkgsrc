# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/06 06:54:54 jlam Exp $
#
# This Makefile fragment is included by packages that use lesstif.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.lesstif to the dependency pattern
#     for the version of lesstif desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(LESSTIF_BUILDLINK2_MK)
LESSTIF_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.lesstif?=	lesstif>=0.91.4
DEPENDS+=	${BUILDLINK_DEPENDS.lesstif}:../../x11/lesstif

EVAL_PREFIX+=	BUILDLINK_PREFIX.lesstif=lesstif
BUILDLINK_PREFIX.lesstif_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.lesstif=	include/Mrm/*
BUILDLINK_FILES.lesstif+=	include/Xm/*
BUILDLINK_FILES.lesstif+=	include/uil/*
BUILDLINK_FILES.lesstif+=	lib/libMrm.*
BUILDLINK_FILES.lesstif+=	lib/libUil.*
BUILDLINK_FILES.lesstif+=	lib/libXm.*

BUILDLINK_TARGETS+=		lesstif-buildlink

lesstif-buildlink: _BUILDLINK_USE

.endif	# LESSTIF_BUILDLINK2_MK
