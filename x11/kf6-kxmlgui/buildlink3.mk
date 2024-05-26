# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 13:47:34 markd Exp $

BUILDLINK_TREE+=	kf6-kxmlgui

.if !defined(KF6_KXMLGUI_BUILDLINK3_MK)
KF6_KXMLGUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kxmlgui+=	kf6-kxmlgui>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kxmlgui?=	../../x11/kf6-kxmlgui

.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../graphics/kf6-kiconthemes/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/kf6-kglobalaccel/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-kitemviews/buildlink3.mk"
.include "../../x11/kf6-ktextwidgets/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KXMLGUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kxmlgui
