# $NetBSD: buildlink3.mk,v 1.2 2026/01/07 08:49:12 wiz Exp $

BUILDLINK_TREE+=	plasma6-knighttime

.if !defined(PLASMA6_KNIGHTTIME_BUILDLINK3_MK)
PLASMA6_KNIGHTTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-knighttime+=	plasma6-knighttime>=6.5.2
BUILDLINK_ABI_DEPENDS.plasma6-knighttime?=	plasma6-knighttime>=6.5.2nb2
BUILDLINK_PKGSRCDIR.plasma6-knighttime?=	../../time/plasma6-knighttime

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../geography/qt6-qtpositioning/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../time/kf6-kholidays/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PLASMA6_KNIGHTTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-knighttime
