# $NetBSD: buildlink3.mk,v 1.31 2023/01/29 21:15:08 ryoon Exp $

BUILDLINK_TREE+=	kactivities-stats

.if !defined(KACTIVITIES_STATS_BUILDLINK3_MK)
KACTIVITIES_STATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kactivities-stats+=	kactivities-stats>=5.41.0
BUILDLINK_ABI_DEPENDS.kactivities-stats?=	kactivities-stats>=5.98.0nb3
BUILDLINK_PKGSRCDIR.kactivities-stats?=		../../x11/kactivities-stats

.include "../../x11/kactivities5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KACTIVITIES_STATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kactivities-stats
