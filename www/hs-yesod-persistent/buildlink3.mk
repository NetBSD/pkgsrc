# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:57 pho Exp $

BUILDLINK_TREE+=	hs-yesod-persistent

.if !defined(HS_YESOD_PERSISTENT_BUILDLINK3_MK)
HS_YESOD_PERSISTENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-yesod-persistent+=	hs-yesod-persistent>=1.6.0
BUILDLINK_ABI_DEPENDS.hs-yesod-persistent+=	hs-yesod-persistent>=1.6.0.8nb2
BUILDLINK_PKGSRCDIR.hs-yesod-persistent?=	../../www/hs-yesod-persistent

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-persistent/buildlink3.mk"
.include "../../devel/hs-persistent-template/buildlink3.mk"
.include "../../devel/hs-resource-pool/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../www/hs-yesod-core/buildlink3.mk"
.endif	# HS_YESOD_PERSISTENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-yesod-persistent
