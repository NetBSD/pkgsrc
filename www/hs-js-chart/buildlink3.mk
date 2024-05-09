# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:54 pho Exp $

BUILDLINK_TREE+=	hs-js-chart

.if !defined(HS_JS_CHART_BUILDLINK3_MK)
HS_JS_CHART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-js-chart+=	hs-js-chart>=2.9.4
BUILDLINK_ABI_DEPENDS.hs-js-chart+=	hs-js-chart>=2.9.4.1nb2
BUILDLINK_PKGSRCDIR.hs-js-chart?=	../../www/hs-js-chart
.endif	# HS_JS_CHART_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-js-chart
