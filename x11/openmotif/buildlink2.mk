# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:32 jlam Exp $
#
# This Makefile fragment is included by packages that use openmotif.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.openmotif to the dependency pattern
#     for the version of openmotif desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(OPENMOTIF_BUILDLINK2_MK)
OPENMOTIF_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

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

BUILDLINK_TARGETS+=		openmotif-buildlink

openmotif-buildlink: _BUILDLINK_USE

.endif	# OPENMOTIF_BUILDLINK2_MK
