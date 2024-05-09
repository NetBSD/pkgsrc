# $NetBSD: buildlink3.mk,v 1.6 2024/05/09 01:32:55 pho Exp $

BUILDLINK_TREE+=	hs-servant

.if !defined(HS_SERVANT_BUILDLINK3_MK)
HS_SERVANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-servant+=	hs-servant>=0.20.1
BUILDLINK_ABI_DEPENDS.hs-servant+=	hs-servant>=0.20.1nb2
BUILDLINK_PKGSRCDIR.hs-servant?=	../../www/hs-servant

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-constraints/buildlink3.mk"
.include "../../www/hs-http-api-data/buildlink3.mk"
.include "../../www/hs-http-media/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-mmorph/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-singleton-bool/buildlink3.mk"
.include "../../devel/hs-sop-core/buildlink3.mk"
.include "../../converters/hs-string-conversions/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-vault/buildlink3.mk"
.endif	# HS_SERVANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-servant
