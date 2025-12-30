# $NetBSD: buildlink3.mk,v 1.1 2025/12/30 02:13:56 markd Exp $

BUILDLINK_TREE+=	plasma6-plasma-activities-stats

.if !defined(PLASMA6_PLASMA_ACTIVITIES_STATS_BUILDLINK3_MK)
PLASMA6_PLASMA_ACTIVITIES_STATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-plasma-activities-stats+=	plasma6-plasma-activities-stats>=6.5.2
BUILDLINK_PKGSRCDIR.plasma6-plasma-activities-stats?=	../../x11/plasma6-plasma-activities-stats

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PLASMA6_PLASMA_ACTIVITIES_STATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-plasma-activities-stats
