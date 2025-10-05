# $NetBSD: buildlink3.mk,v 1.5 2025/10/05 19:26:25 js Exp $

BUILDLINK_TREE+=	hs-curl

.if !defined(HS_CURL_BUILDLINK3_MK)
HS_CURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-curl+=	hs-curl>=1.3.8
BUILDLINK_ABI_DEPENDS.hs-curl+=	hs-curl>=1.3.8nb4
BUILDLINK_PKGSRCDIR.hs-curl?=	../../www/hs-curl

.include "../../www/curl/buildlink3.mk"
.endif	# HS_CURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-curl
