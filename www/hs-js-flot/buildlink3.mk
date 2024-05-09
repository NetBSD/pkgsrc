# $NetBSD: buildlink3.mk,v 1.8 2024/05/09 01:32:54 pho Exp $

BUILDLINK_TREE+=	hs-js-flot

.if !defined(HS_JS_FLOT_BUILDLINK3_MK)
HS_JS_FLOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-js-flot+=	hs-js-flot>=0.8.3
BUILDLINK_ABI_DEPENDS.hs-js-flot+=	hs-js-flot>=0.8.3nb7
BUILDLINK_PKGSRCDIR.hs-js-flot?=	../../www/hs-js-flot
.endif	# HS_JS_FLOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-js-flot
