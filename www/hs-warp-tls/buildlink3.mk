# $NetBSD: buildlink3.mk,v 1.20 2025/08/13 11:07:46 pho Exp $

BUILDLINK_TREE+=	hs-warp-tls

.if !defined(HS_WARP_TLS_BUILDLINK3_MK)
HS_WARP_TLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-warp-tls+=	hs-warp-tls>=3.4.12
BUILDLINK_ABI_DEPENDS.hs-warp-tls+=	hs-warp-tls>=3.4.12nb4
BUILDLINK_PKGSRCDIR.hs-warp-tls?=	../../www/hs-warp-tls

.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-streaming-commons/buildlink3.mk"
.include "../../security/hs-tls-session-manager/buildlink3.mk"
.include "../../net/hs-recv/buildlink3.mk"
.endif	# HS_WARP_TLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-warp-tls
