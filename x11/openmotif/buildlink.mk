# $NetBSD: buildlink.mk,v 1.2 2001/09/13 08:09:42 jlam Exp $
#
# This Makefile fragment is included by packages that use openmotif.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.openmotif to the dependency pattern
#     for the version of openmotif desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(OPENMOTIF_BUILDLINK_MK)
OPENMOTIF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.openmotif?=	openmotif>=2.1.30
DEPENDS+=	${BUILDLINK_DEPENDS.openmotif}:../../x11/openmotif

EVAL_PREFIX+=			BUILDLINK_PREFIX.openmotif=openmotif
BUILDLINK_PREFIX.openmotif_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.openmotif=	include/Mrm/*
BUILDLINK_FILES.openmotif+=	include/Xm/*
BUILDLINK_FILES.openmotif+=	include/uil/*
BUILDLINK_FILES.openmotif+=	lib/libMrm.*
BUILDLINK_FILES.openmotif+=	lib/libUil.*
BUILDLINK_FILES.openmotif+=	lib/libXm.*

BUILDLINK_TARGETS.openmotif=	openmotif-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.openmotif}

pre-configure: ${BUILDLINK_TARGETS.openmotif}
openmotif-buildlink: _BUILDLINK_USE

.endif	# OPENMOTIF_BUILDLINK_MK
