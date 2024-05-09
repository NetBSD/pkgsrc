# $NetBSD: buildlink3.mk,v 1.7 2024/05/09 01:32:55 pho Exp $

BUILDLINK_TREE+=	hs-wai-app-static

.if !defined(HS_WAI_APP_STATIC_BUILDLINK3_MK)
HS_WAI_APP_STATIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-wai-app-static+=	hs-wai-app-static>=3.1.9
BUILDLINK_ABI_DEPENDS.hs-wai-app-static+=	hs-wai-app-static>=3.1.9nb1
BUILDLINK_PKGSRCDIR.hs-wai-app-static?=		../../www/hs-wai-app-static

.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../www/hs-http-date/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../net/hs-mime-types/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-wai-extra/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.endif	# HS_WAI_APP_STATIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-wai-app-static
