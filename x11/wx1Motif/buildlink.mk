# $NetBSD: buildlink.mk,v 1.1.1.1 2002/06/17 02:24:56 dmcmahill Exp $
#
# This Makefile fragment is included by packages that use wx1Motif.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.wx1Motif to the dependency pattern
#     for the version of wx1Motif desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(WX1MOTIF_BUILDLINK_MK)
WX1MOTIF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.wx1Motif?=	wx1Motif>=1.68e
DEPENDS+=			${BUILDLINK_DEPENDS.wx1Motif}:../../x11/wx1Motif

EVAL_PREFIX+=			BUILDLINK_PREFIX.wx1Motif=wx1Motif
BUILDLINK_PREFIX.wx1Motif_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.wx1Motif=		include/wxwindows1/*
BUILDLINK_FILES.wx1Motif+=		lib/wxwindows1/libwx_motif.a

.if !defined(_BUILDLINK_WX1MOTIF_CPPFLAGS) || \
	!defined(_BUILDLINK_WX1MOTIF_LDFLAGS)
_BUILDLINK_WX1MOTIF_CPPFLAGS=        -I${BUILDLINK_DIR}/include/wxwindows1
_BUILDLINK_WX1MOTIF_LDFLAGS=         -L${BUILDLINK_DIR}/lib/wxwindows1

CFLAGS+=                ${_BUILDLINK_WX1MOTIF_CPPFLAGS}
CXXFLAGS+=              ${_BUILDLINK_WX1MOTIF_CPPFLAGS}
CPPFLAGS+=              ${_BUILDLINK_WX1MOTIF_CPPFLAGS}
LDFLAGS+=               ${_BUILDLINK_WX1MOTIF_LDFLAGS}
.endif

.include "../../mk/motif.buildlink.mk"

BUILDLINK_TARGETS.wx1Motif=	wx1Motif-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.wx1Motif}

pre-configure: ${BUILDLINK_TARGETS.wx1Motif}
wx1Motif-buildlink: _BUILDLINK_USE

.endif	# WX1MOTIF_BUILDLINK_MK
