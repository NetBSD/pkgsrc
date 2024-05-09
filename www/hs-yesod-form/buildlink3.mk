# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:57 pho Exp $

BUILDLINK_TREE+=	hs-yesod-form

.if !defined(HS_YESOD_FORM_BUILDLINK3_MK)
HS_YESOD_FORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-yesod-form+=	hs-yesod-form>=1.7.6
BUILDLINK_ABI_DEPENDS.hs-yesod-form+=	hs-yesod-form>=1.7.6nb2
BUILDLINK_PKGSRCDIR.hs-yesod-form?=	../../www/hs-yesod-form

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../devel/hs-byteable/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../mail/hs-email-validate/buildlink3.mk"
.include "../../devel/hs-persistent/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../textproc/hs-shakespeare/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-xss-sanitize/buildlink3.mk"
.include "../../www/hs-yesod-core/buildlink3.mk"
.include "../../www/hs-yesod-persistent/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.endif	# HS_YESOD_FORM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-yesod-form
