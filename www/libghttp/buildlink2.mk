# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:40:20 jlam Exp $

.if !defined(LIBGHTTP_BUILDLINK2_MK)
LIBGHTTP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libghttp
BUILDLINK_DEPENDS.libghttp?=	libghttp>=1.0.9
BUILDLINK_PKGSRCDIR.libghttp?=	../../www/libghttp

EVAL_PREFIX+=			BUILDLINK_PREFIX.libghttp=libghttp
BUILDLINK_PREFIX.libghttp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libghttp=	include/ghttp*
BUILDLINK_FILES.libghttp+=	lib/libghttp.*

BUILDLINK_TARGETS+=	libghttp-buildlink

libghttp-buildlink: _BUILDLINK_USE

.endif	# LIBGHTTP_BUILDLINK2_MK
