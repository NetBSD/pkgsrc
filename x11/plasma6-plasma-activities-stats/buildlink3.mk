# $NetBSD: buildlink3.mk,v 1.7 2026/09/29 06:08:31 wiz Exp $

BUILDLINK_TREE+=	plasma6-plasma-activities-stats

.if !defined(PLASMA6_PLASMA_ACTIVITIES_STATS_BUILDLINK3_MK)
PLASMA6_PLASMA_ACTIVITIES_STATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-plasma-activities-stats+=	plasma6-plasma-activities-stats>=6.5.2
BUILDLINK_ABI_DEPENDS.plasma6-plasma-activities-stats?=	plasma6-plasma-activities-stats>=6.7.4nb2
BUILDLINK_PKGSRCDIR.plasma6-plasma-activities-stats?=	../../x11/plasma6-plasma-activities-stats

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PLASMA6_PLASMA_ACTIVITIES_STATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-plasma-activities-stats
