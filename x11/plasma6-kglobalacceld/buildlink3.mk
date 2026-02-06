# $NetBSD: buildlink3.mk,v 1.4 2026/02/06 10:06:17 wiz Exp $

BUILDLINK_TREE+=	plasma6-kglobalacceld

.if !defined(PLASMA6_KGLOBALACCELD_BUILDLINK3_MK)
PLASMA6_KGLOBALACCELD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-kglobalacceld+=	plasma6-kglobalacceld>=6.5.2
BUILDLINK_ABI_DEPENDS.plasma6-kglobalacceld?=	plasma6-kglobalacceld>=6.5.2nb5
BUILDLINK_PKGSRCDIR.plasma6-kglobalacceld?=	../../x11/plasma6-kglobalacceld

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../x11/kf6-kglobalaccel/buildlink3.mk"
.include "../../x11/kf6-kjobwidgets/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.endif	# PLASMA6_KGLOBALACCELD_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-kglobalacceld
