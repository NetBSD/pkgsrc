# $NetBSD: buildlink3.mk,v 1.10 2025/03/05 03:40:11 pho Exp $

BUILDLINK_TREE+=	hs-js-jquery

.if !defined(HS_JS_JQUERY_BUILDLINK3_MK)
HS_JS_JQUERY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-js-jquery+=	hs-js-jquery>=3.3.1
BUILDLINK_ABI_DEPENDS.hs-js-jquery?=	hs-js-jquery>=3.3.1nb9
BUILDLINK_PKGSRCDIR.hs-js-jquery?=	../../www/hs-js-jquery
.endif	# HS_JS_JQUERY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-js-jquery
