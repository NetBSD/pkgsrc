# $NetBSD: buildlink.mk,v 1.8 2001/09/13 08:09:41 jlam Exp $
#
# This Makefile fragment is included by packages that use lesstif.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.lesstif to the dependency pattern
#     for the version of lesstif desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LESSTIF_BUILDLINK_MK)
LESSTIF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.lesstif?=	lesstif>=0.91.4
DEPENDS+=	${BUILDLINK_DEPENDS.lesstif}:../../x11/lesstif

EVAL_PREFIX+=			BUILDLINK_PREFIX.lesstif=lesstif
BUILDLINK_PREFIX.lesstif_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.lesstif=	include/Mrm/*
BUILDLINK_FILES.lesstif+=	include/Xm/*
BUILDLINK_FILES.lesstif+=	include/uil/*
BUILDLINK_FILES.lesstif+=	lib/libMrm.*
BUILDLINK_FILES.lesstif+=	lib/libUil.*
BUILDLINK_FILES.lesstif+=	lib/libXm.*

BUILDLINK_TARGETS.lesstif=	lesstif-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.lesstif}

pre-configure: ${BUILDLINK_TARGETS.lesstif}
lesstif-buildlink: _BUILDLINK_USE

.endif	# LESSTIF_BUILDLINK_MK
