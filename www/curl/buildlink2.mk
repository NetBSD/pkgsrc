# $NetBSD: buildlink2.mk,v 1.3 2004/02/19 01:24:01 wiz Exp $

.if !defined(CURL_BUILDLINK2_MK)
CURL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		curl
BUILDLINK_DEPENDS.curl?=	curl>=7.9.1
BUILDLINK_PKGSRCDIR.curl?=	../../www/curl

EVAL_PREFIX+=	BUILDLINK_PREFIX.curl=curl
BUILDLINK_PREFIX.curl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.curl=	include/curl/*
BUILDLINK_FILES.curl+=	lib/libcurl.*

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

BUILDLINK_TARGETS+=	curl-buildlink

curl-buildlink: _BUILDLINK_USE

.endif	# CURL_BUILDLINK2_MK
