# $NetBSD: buildlink3.mk,v 1.1 2016/05/26 09:49:48 markd Exp $

BUILDLINK_TREE+=	kconfigwidgets

.if !defined(KCONFIGWIDGETS_BUILDLINK3_MK)
KCONFIGWIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kconfigwidgets+=	kconfigwidgets>=5.19.0
BUILDLINK_PKGSRCDIR.kconfigwidgets?=	../../x11/kconfigwidgets

.include "../../devel/kconfig/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../security/kauth/buildlink3.mk"
.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../x11/kguiaddons/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCONFIGWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kconfigwidgets
