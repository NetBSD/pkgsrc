# $NetBSD: buildlink.mk,v 1.1 2001/08/05 17:04:21 sakamoto Exp $
#
# This Makefile fragment is included by packages that use fox.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.fox to the dependency pattern
#     for the version of fox desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(FOX_BUILDLINK_MK)
FOX_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.fox?=	fox-*
DEPENDS+=	${BUILDLINK_DEPENDS.fox}:../../x11/fox

EVAL_PREFIX+=		BUILDLINK_PREFIX.fox=fox
BUILDLINK_PREFIX.fox_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.fox=	include/fox/*
BUILDLINK_FILES.fox+=	lib/libFOX-*
BUILDLINK_FILES.fox+=	lib/libFOX.*

BUILDLINK_TARGETS.fox=	fox-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.fox}

CPPFLAGS+=	-I${BUILDLINK_DIR}/include/fox

pre-configure: ${BUILDLINK_TARGETS.fox}
fox-buildlink: _BUILDLINK_USE

.endif	# FOX_BUILDLINK_MK
