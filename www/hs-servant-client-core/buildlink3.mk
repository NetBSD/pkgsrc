# $NetBSD: buildlink3.mk,v 1.2 2025/02/02 13:06:06 pho Exp $

BUILDLINK_TREE+=	hs-servant-client-core

.if !defined(HS_SERVANT_CLIENT_CORE_BUILDLINK3_MK)
HS_SERVANT_CLIENT_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-servant-client-core+=	hs-servant-client-core>=0.20.2
BUILDLINK_ABI_DEPENDS.hs-servant-client-core+=	hs-servant-client-core>=0.20.2nb1
BUILDLINK_PKGSRCDIR.hs-servant-client-core?=	../../www/hs-servant-client-core

.include "../../devel/hs-constraints/buildlink3.mk"
.include "../../www/hs-servant/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../math/hs-free/buildlink3.mk"
.include "../../www/hs-http-media/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-sop-core/buildlink3.mk"
.endif	# HS_SERVANT_CLIENT_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-servant-client-core
