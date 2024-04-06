# $NetBSD: buildlink3.mk,v 1.39 2024/04/06 08:06:59 wiz Exp $

BUILDLINK_TREE+=	kactivities-stats

.if !defined(KACTIVITIES_STATS_BUILDLINK3_MK)
KACTIVITIES_STATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kactivities-stats+=	kactivities-stats>=5.41.0
BUILDLINK_ABI_DEPENDS.kactivities-stats?=	kactivities-stats>=5.114.0nb1
BUILDLINK_PKGSRCDIR.kactivities-stats?=		../../x11/kactivities-stats

.include "../../x11/kactivities5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KACTIVITIES_STATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kactivities-stats
