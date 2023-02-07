# $NetBSD: buildlink3.mk,v 1.5 2023/02/07 01:41:19 pho Exp $

BUILDLINK_TREE+=	hs-wai

.if !defined(HS_WAI_BUILDLINK3_MK)
HS_WAI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-wai+=	hs-wai>=3.2.3
BUILDLINK_ABI_DEPENDS.hs-wai+=	hs-wai>=3.2.3nb4
BUILDLINK_PKGSRCDIR.hs-wai?=	../../www/hs-wai

.include "../../www/hs-http-types/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-vault/buildlink3.mk"
.endif	# HS_WAI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-wai
