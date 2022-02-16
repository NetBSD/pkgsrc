# $NetBSD: buildlink3.mk,v 1.1 2022/02/16 09:44:49 pho Exp $

BUILDLINK_TREE+=	hs-js-dgtable

.if !defined(HS_JS_DGTABLE_BUILDLINK3_MK)
HS_JS_DGTABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-js-dgtable+=	hs-js-dgtable>=0.5.2
BUILDLINK_ABI_DEPENDS.hs-js-dgtable+=	hs-js-dgtable>=0.5.2
BUILDLINK_PKGSRCDIR.hs-js-dgtable?=	../../www/hs-js-dgtable
.endif	# HS_JS_DGTABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-js-dgtable
