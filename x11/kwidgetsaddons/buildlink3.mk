# $NetBSD: buildlink3.mk,v 1.12 2018/12/09 18:52:12 adam Exp $

BUILDLINK_TREE+=	kwidgetsaddons

.if !defined(KWIDGETSADDONS_BUILDLINK3_MK)
KWIDGETSADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kwidgetsaddons+=	kwidgetsaddons>=5.18.0
BUILDLINK_ABI_DEPENDS.kwidgetsaddons?=	kwidgetsaddons>=5.47.0nb4
BUILDLINK_PKGSRCDIR.kwidgetsaddons?=	../../x11/kwidgetsaddons

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KWIDGETSADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kwidgetsaddons
