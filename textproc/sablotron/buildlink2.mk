# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:40:14 jlam Exp $

.if !defined(SABLOTRON_BUILDLINK2_MK)
SABLOTRON_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		sablotron
BUILDLINK_DEPENDS.sablotron?=	sablotron>=0.71
BUILDLINK_PKGSRCDIR.sablotron?=	../../textproc/sablotron

EVAL_PREFIX+=		BUILDLINK_PREFIX.sablotron=sablotron
BUILDLINK_PREFIX.sablotron_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.sablotron=	include/sablot.h
BUILDLINK_FILES.sablotron+=	include/sdom.h
BUILDLINK_FILES.sablotron+=	include/shandler.h
BUILDLINK_FILES.sablotron+=	include/sxpath.h
BUILDLINK_FILES.sablotron+=	lib/libsablot.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"

BUILDLINK_TARGETS+=	sablotron-buildlink

sablotron-buildlink: _BUILDLINK_USE

.endif	# SABLOTRON_BUILDLINK2_MK
