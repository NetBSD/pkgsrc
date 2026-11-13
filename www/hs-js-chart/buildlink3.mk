# $NetBSD: buildlink3.mk,v 1.7 2026/11/13 14:40:04 pho Exp $

BUILDLINK_TREE+=	hs-js-chart

.if !defined(HS_JS_CHART_BUILDLINK3_MK)
HS_JS_CHART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-js-chart+=	hs-js-chart>=2.9.4
BUILDLINK_ABI_DEPENDS.hs-js-chart+=	hs-js-chart>=2.9.4.1nb6
BUILDLINK_PKGSRCDIR.hs-js-chart?=	../../www/hs-js-chart
.endif	# HS_JS_CHART_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-js-chart
