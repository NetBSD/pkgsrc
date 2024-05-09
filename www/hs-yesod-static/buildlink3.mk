# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:57 pho Exp $

BUILDLINK_TREE+=	hs-yesod-static

.if !defined(HS_YESOD_STATIC_BUILDLINK3_MK)
HS_YESOD_STATIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-yesod-static+=	hs-yesod-static>=1.6.1
BUILDLINK_ABI_DEPENDS.hs-yesod-static+=	hs-yesod-static>=1.6.1.0nb2
BUILDLINK_PKGSRCDIR.hs-yesod-static?=	../../www/hs-yesod-static

.include "../../devel/hs-async/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../security/hs-crypton-conduit/buildlink3.mk"
.include "../../textproc/hs-css-text/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../lang/hjsmin/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../net/hs-mime-types/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-wai-app-static/buildlink3.mk"
.include "../../www/hs-yesod-core/buildlink3.mk"
.endif	# HS_YESOD_STATIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-yesod-static
