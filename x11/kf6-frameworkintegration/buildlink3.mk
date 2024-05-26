# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 13:23:46 markd Exp $

BUILDLINK_TREE+=	kf6-frameworkintegration

.if !defined(KF6_FRAMEWORKINTEGRATION_BUILDLINK3_MK)
KF6_FRAMEWORKINTEGRATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-frameworkintegration+=	kf6-frameworkintegration>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-frameworkintegration?=		../../x11/kf6-frameworkintegration

.include "../../devel/kf6-kcolorscheme/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/kf6-kpackage/buildlink3.mk"
.include "../../graphics/kf6-kiconthemes/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_FRAMEWORKINTEGRATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-frameworkintegration
