# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:40:40 jlam Exp $

.if !defined(OPENMOTIF_BUILDLINK2_MK)
OPENMOTIF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		openmotif
BUILDLINK_DEPENDS.openmotif?=	openmotif>=2.1.30
BUILDLINK_PKGSRCDIR.openmotif?=	../../x11/openmotif

EVAL_PREFIX+=	BUILDLINK_PREFIX.openmotif=openmotif
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
