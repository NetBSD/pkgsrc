# $NetBSD: buildlink.mk,v 1.8 2001/09/13 22:06:34 jlam Exp $
#
# This Makefile fragment is included by packages that use lesstif12.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.lesstif12 to the dependency pattern
#     for the version of lesstif12 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LESSTIF12_BUILDLINK_MK)
LESSTIF12_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.lesstif12?=	lesstif12>=0.91.4
DEPENDS+=	${BUILDLINK_DEPENDS.lesstif12}:../../x11/lesstif12

EVAL_PREFIX+=			LESSTIF12_PREFIX=lesstif12
LESSTIF12_PREFIX_DEFAULT=	${X11PREFIX}
BUILDLINK_PREFIX.lesstif12=	${LESSTIF12_PREFIX}/LessTif/Motif1.2
BUILDLINK_FILES.lesstif12=	include/Mrm/*
BUILDLINK_FILES.lesstif12+=	include/Xm/*
BUILDLINK_FILES.lesstif12+=	include/uil/*
BUILDLINK_FILES.lesstif12+=	lib/libMrm.*
BUILDLINK_FILES.lesstif12+=	lib/libUil.*
BUILDLINK_FILES.lesstif12+=	lib/libXm.*

BUILDLINK_TARGETS.lesstif12=	lesstif12-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.lesstif12}

pre-configure: ${BUILDLINK_TARGETS.lesstif12}
lesstif12-buildlink: _BUILDLINK_USE

.endif	# LESSTIF12_BUILDLINK_MK
