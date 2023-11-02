# $NetBSD: buildlink3.mk,v 1.1 2023/11/02 02:34:39 pho Exp $

BUILDLINK_TREE+=	hs-js-chart

.if !defined(HS_JS_CHART_BUILDLINK3_MK)
HS_JS_CHART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-js-chart+=	hs-js-chart>=2.9.4
BUILDLINK_ABI_DEPENDS.hs-js-chart+=	hs-js-chart>=2.9.4.1
BUILDLINK_PKGSRCDIR.hs-js-chart?=	../../www/hs-js-chart
.endif	# HS_JS_CHART_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-js-chart
