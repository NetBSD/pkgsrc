# $NetBSD: buildlink.mk,v 1.3 2002/01/01 03:11:18 jlam Exp $
#
# This Makefile fragment is included by packages that use sablotron.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.sablotron to the dependency pattern
#     for the version of sablotron desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(SABLOTRON_BUILDLINK_MK)
SABLOTRON_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.sablotron?=	sablotron>=0.71
DEPENDS+=	${BUILDLINK_DEPENDS.sablotron}:../../textproc/sablotron

EVAL_PREFIX+=		BUILDLINK_PREFIX.sablotron=sablotron
BUILDLINK_PREFIX.sablotron_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.sablotron=	include/sablot.h
BUILDLINK_FILES.sablotron+=	include/sdom.h
BUILDLINK_FILES.sablotron+=	include/shandler.h
BUILDLINK_FILES.sablotron+=	lib/libsablot.*

.include "../../converters/libiconv/buildlink.mk"
.include "../../textproc/expat/buildlink.mk"

BUILDLINK_TARGETS.sablotron=	sablotron-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.sablotron}

pre-configure: ${BUILDLINK_TARGETS.sablotron}
sablotron-buildlink: _BUILDLINK_USE

.endif	# SABLOTRON_BUILDLINK_MK
