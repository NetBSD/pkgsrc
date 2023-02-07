# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:41:19 pho Exp $

BUILDLINK_TREE+=	hs-wai-websockets

.if !defined(HS_WAI_WEBSOCKETS_BUILDLINK3_MK)
HS_WAI_WEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-wai-websockets+=	hs-wai-websockets>=3.0.1
BUILDLINK_ABI_DEPENDS.hs-wai-websockets+=	hs-wai-websockets>=3.0.1.2nb3
BUILDLINK_PKGSRCDIR.hs-wai-websockets?=		../../www/hs-wai-websockets

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-websockets/buildlink3.mk"
.endif	# HS_WAI_WEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-wai-websockets
