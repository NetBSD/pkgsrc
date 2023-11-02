# $NetBSD: buildlink3.mk,v 1.13 2023/11/02 06:37:48 pho Exp $

BUILDLINK_TREE+=	hs-warp-tls

.if !defined(HS_WARP_TLS_BUILDLINK3_MK)
HS_WARP_TLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-warp-tls+=	hs-warp-tls>=3.4.3
BUILDLINK_ABI_DEPENDS.hs-warp-tls+=	hs-warp-tls>=3.4.3nb1
BUILDLINK_PKGSRCDIR.hs-warp-tls?=	../../www/hs-warp-tls

.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-recv/buildlink3.mk"
.include "../../devel/hs-streaming-commons/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.include "../../security/hs-tls-session-manager/buildlink3.mk"
.include "../../devel/hs-unliftio/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.endif	# HS_WARP_TLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-warp-tls
