# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/08/30 16:18:58 xtraeme Exp $
#
# This Makefile fragment is included by packages that use raptor.
#
# This file was created automatically using createbuildlink 2.5.
#

.if !defined(RAPTOR_BUILDLINK2_MK)
RAPTOR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			raptor
BUILDLINK_DEPENDS.raptor?=		raptor>=0.9.10
BUILDLINK_PKGSRCDIR.raptor?=		../../wip/raptor

EVAL_PREFIX+=	BUILDLINK_PREFIX.raptor=raptor
BUILDLINK_PREFIX.raptor_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.raptor+=	include/ntriples.h
BUILDLINK_FILES.raptor+=	include/raptor.h
BUILDLINK_FILES.raptor+=	lib/libraptor.*
BUILDLINK_FILES.raptor+=	lib/pkgconfig/raptor.pc

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"

BUILDLINK_TARGETS+=	raptor-buildlink

raptor-buildlink: _BUILDLINK_USE

.endif	# RAPTOR_BUILDLINK2_MK
