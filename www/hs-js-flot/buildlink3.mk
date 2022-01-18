# $NetBSD: buildlink3.mk,v 1.2 2022/01/18 02:48:32 pho Exp $

BUILDLINK_TREE+=	hs-js-flot

.if !defined(HS_JS_FLOT_BUILDLINK3_MK)
HS_JS_FLOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-js-flot+=	hs-js-flot>=0.8.3
BUILDLINK_ABI_DEPENDS.hs-js-flot+=	hs-js-flot>=0.8.3nb1
BUILDLINK_PKGSRCDIR.hs-js-flot?=	../../www/hs-js-flot
.endif	# HS_JS_FLOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-js-flot
