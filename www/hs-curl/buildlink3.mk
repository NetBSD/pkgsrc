# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 13:35:20 pho Exp $

BUILDLINK_TREE+=	hs-curl

.if !defined(HS_CURL_BUILDLINK3_MK)
HS_CURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-curl+=	hs-curl>=1.3.8
BUILDLINK_ABI_DEPENDS.hs-curl+=	hs-curl>=1.3.8
BUILDLINK_PKGSRCDIR.hs-curl?=	../../www/hs-curl

.include "../../www/curl/buildlink3.mk"
.endif	# HS_CURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-curl
