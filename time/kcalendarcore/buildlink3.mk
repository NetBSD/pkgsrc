# $NetBSD: buildlink3.mk,v 1.13 2023/04/19 08:08:47 adam Exp $

BUILDLINK_TREE+=	kcalendarcore

.if !defined(KCALENDARCORE_BUILDLINK3_MK)
KCALENDARCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcalendarcore+=	kcalendarcore>=5.64.0
BUILDLINK_ABI_DEPENDS.kcalendarcore?=	kcalendarcore>=5.98.0nb4
BUILDLINK_PKGSRCDIR.kcalendarcore?=	../../time/kcalendarcore

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCALENDARCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcalendarcore
