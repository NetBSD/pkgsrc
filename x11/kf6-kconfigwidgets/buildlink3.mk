# $NetBSD: buildlink3.mk,v 1.2 2024/11/01 00:54:16 wiz Exp $

BUILDLINK_TREE+=	kf6-kconfigwidgets

.if !defined(KF6_KCONFIGWIDGETS_BUILDLINK3_MK)
KF6_KCONFIGWIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kconfigwidgets+=	kf6-kconfigwidgets>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kconfigwidgets?=	kf6-kconfigwidgets>=6.2.0nb2
BUILDLINK_PKGSRCDIR.kf6-kconfigwidgets?=	../../x11/kf6-kconfigwidgets

.include "../../devel/kf6-kcolorscheme/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../security/kf6-kauth/buildlink3.mk"
.include "../../textproc/kf6-kcodecs/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KCONFIGWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kconfigwidgets
