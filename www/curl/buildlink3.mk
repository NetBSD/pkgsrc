# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:41 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CURL_BUILDLINK3_MK:=	${CURL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	curl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncurl}
BUILDLINK_PACKAGES+=	curl

.if !empty(CURL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.curl+=	curl>=7.9.1
BUILDLINK_PKGSRCDIR.curl?=	../../www/curl

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.endif	# CURL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
