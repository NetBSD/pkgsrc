# $NetBSD: buildlink.mk,v 1.1.1.1 2002/08/02 20:10:47 jlam Exp $
#
# This Makefile fragment is included by packages that use neXtaw.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.neXtaw to the dependency pattern
#     for the version of neXtaw desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(NEXTAW_BUILDLINK_MK)
NEXTAW_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.neXtaw?=	neXtaw>=0.12
DEPENDS+=	${BUILDLINK_DEPENDS.neXtaw}:../../x11/neXtaw

EVAL_PREFIX+=	BUILDLINK_PREFIX.neXtaw=neXtaw
BUILDLINK_PREFIX.neXtaw_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.neXtaw+=		include/X11/neXtaw/*
BUILDLINK_FILES.neXtaw+=		lib/libneXtaw.*

BUILDLINK_TARGETS.neXtaw+=	neXtaw-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.neXtaw}

LIBXAW?=	-L${BUILDLINK_DIR}/lib -lneXtaw
MAKE_ENV+=	LIBXAW="${LIBXAW}"

pre-configure: ${BUILDLINK_TARGETS.neXtaw}
neXtaw-buildlink: _BUILDLINK_USE

.endif	# NEXTAW_BUILDLINK_MK
