# $NetBSD: buildlink.mk,v 1.4 2001/07/27 13:33:36 jlam Exp $
#
# This Makefile fragment is included by packages that use libghttp.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libghttp to the dependency pattern
#     for the version of libghttp desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBGHTTP_BUILDLINK_MK)
LIBGHTTP_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libghttp?=	libghttp>=1.0.9
DEPENDS+=	${BUILDLINK_DEPENDS.libghttp}:../../www/libghttp

EVAL_PREFIX+=			BUILDLINK_PREFIX.libghttp=libghttp
BUILDLINK_PREFIX.libghttp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libghttp=	include/ghttp*
BUILDLINK_FILES.libghttp+=	lib/libghttp.*

BUILDLINK_TARGETS.libghttp=	libghttp-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.libghttp}

pre-configure: ${BUILDLINK_TARGETS.libghttp}
libghttp-buildlink: _BUILDLINK_USE

.endif	# LIBGHTTP_BUILDLINK_MK
