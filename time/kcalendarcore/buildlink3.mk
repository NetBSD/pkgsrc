# $NetBSD: buildlink3.mk,v 1.23 2025/04/24 14:15:57 wiz Exp $

BUILDLINK_TREE+=	kcalendarcore

.if !defined(KCALENDARCORE_BUILDLINK3_MK)
KCALENDARCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcalendarcore+=	kcalendarcore>=5.64.0
BUILDLINK_ABI_DEPENDS.kcalendarcore?=	kcalendarcore>=5.116.0nb5
BUILDLINK_PKGSRCDIR.kcalendarcore?=	../../time/kcalendarcore

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCALENDARCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcalendarcore
