# $NetBSD: buildlink3.mk,v 1.11 2018/11/12 03:51:32 ryoon Exp $

BUILDLINK_TREE+=	kwidgetsaddons

.if !defined(KWIDGETSADDONS_BUILDLINK3_MK)
KWIDGETSADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kwidgetsaddons+=	kwidgetsaddons>=5.18.0
BUILDLINK_ABI_DEPENDS.kwidgetsaddons?=	kwidgetsaddons>=5.47.0nb3
BUILDLINK_PKGSRCDIR.kwidgetsaddons?=	../../x11/kwidgetsaddons

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KWIDGETSADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kwidgetsaddons
