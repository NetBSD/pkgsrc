# $NetBSD: buildlink3.mk,v 1.2 2025/02/02 13:06:05 pho Exp $

BUILDLINK_TREE+=	hs-servant-client

.if !defined(HS_SERVANT_CLIENT_BUILDLINK3_MK)
HS_SERVANT_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-servant-client+=	hs-servant-client>=0.20.2
BUILDLINK_ABI_DEPENDS.hs-servant-client+=	hs-servant-client>=0.20.2nb1
BUILDLINK_PKGSRCDIR.hs-servant-client?=		../../www/hs-servant-client

.include "../../www/hs-servant/buildlink3.mk"
.include "../../www/hs-servant-client-core/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-media/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../math/hs-kan-extensions/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.endif	# HS_SERVANT_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-servant-client
