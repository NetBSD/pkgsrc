# $NetBSD: buildlink3.mk,v 1.7 2024/05/09 01:32:56 pho Exp $

BUILDLINK_TREE+=	hs-wai-websockets

.if !defined(HS_WAI_WEBSOCKETS_BUILDLINK3_MK)
HS_WAI_WEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-wai-websockets+=	hs-wai-websockets>=3.0.1
BUILDLINK_ABI_DEPENDS.hs-wai-websockets+=	hs-wai-websockets>=3.0.1.2nb6
BUILDLINK_PKGSRCDIR.hs-wai-websockets?=		../../www/hs-wai-websockets

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-websockets/buildlink3.mk"
.endif	# HS_WAI_WEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-wai-websockets
