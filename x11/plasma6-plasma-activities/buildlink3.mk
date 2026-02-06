# $NetBSD: buildlink3.mk,v 1.4 2026/02/06 10:06:18 wiz Exp $

BUILDLINK_TREE+=	plasma6-plasma-activities

.if !defined(PLASMA6_PLASMA_ACTIVITIES_BUILDLINK3_MK)
PLASMA6_PLASMA_ACTIVITIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-plasma-activities+=	plasma6-plasma-activities>=6.5.2
BUILDLINK_ABI_DEPENDS.plasma6-plasma-activities?=		plasma6-plasma-activities>=6.5.2nb2
BUILDLINK_PKGSRCDIR.plasma6-plasma-activities?=		../../x11/plasma6-plasma-activities

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PLASMA6_PLASMA_ACTIVITIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-plasma-activities
