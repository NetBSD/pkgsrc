# $NetBSD: buildlink3.mk,v 1.1 2004/02/19 01:24:01 wiz Exp $
#
# This Makefile fragment is included by packages that use curl.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CURL_BUILDLINK3_MK:=	${CURL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	curl
.endif

.if !empty(CURL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			curl
BUILDLINK_DEPENDS.curl+=		curl>=7.9.1
BUILDLINK_PKGSRCDIR.curl?=		../../www/curl

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.endif # CURL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
