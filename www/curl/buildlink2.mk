# $NetBSD: buildlink2.mk,v 1.1 2002/09/05 20:40:01 jlam Exp $

.if !defined(CURL_BUILDLINK2_MK)
CURL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		curl
BUILDLINK_DEPENDS.curl?=	curl>=7.9.1
BUILDLINK_PKGSRCDIR.curl?=	../../www/curl

EVAL_PREFIX+=	BUILDLINK_PREFIX.curl=curl
BUILDLINK_PREFIX.curl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.curl=	include/curl/*
BUILDLINK_FILES.curl+=	lib/libcurl.*

BUILDLINK_TARGETS+=	curl-buildlink

curl-buildlink: _BUILDLINK_USE

.endif	# CURL_BUILDLINK2_MK
