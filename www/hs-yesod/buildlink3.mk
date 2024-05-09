# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:56 pho Exp $

BUILDLINK_TREE+=	hs-yesod

.if !defined(HS_YESOD_BUILDLINK3_MK)
HS_YESOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-yesod+=	hs-yesod>=1.6.2
BUILDLINK_ABI_DEPENDS.hs-yesod+=	hs-yesod>=1.6.2.1nb2
BUILDLINK_PKGSRCDIR.hs-yesod?=		../../www/hs-yesod

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../sysutils/hs-fast-logger/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../devel/hs-monad-logger/buildlink3.mk"
.include "../../textproc/hs-shakespeare/buildlink3.mk"
.include "../../devel/hs-streaming-commons/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-wai-extra/buildlink3.mk"
.include "../../www/hs-wai-logger/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.include "../../www/hs-yesod-core/buildlink3.mk"
.include "../../www/hs-yesod-form/buildlink3.mk"
.include "../../www/hs-yesod-persistent/buildlink3.mk"
.endif	# HS_YESOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-yesod
