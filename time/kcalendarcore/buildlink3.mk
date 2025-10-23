# $NetBSD: buildlink3.mk,v 1.24 2025/10/23 20:39:38 wiz Exp $

BUILDLINK_TREE+=	kcalendarcore

.if !defined(KCALENDARCORE_BUILDLINK3_MK)
KCALENDARCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcalendarcore+=	kcalendarcore>=5.64.0
BUILDLINK_ABI_DEPENDS.kcalendarcore?=	kcalendarcore>=5.116.0nb6
BUILDLINK_PKGSRCDIR.kcalendarcore?=	../../time/kcalendarcore

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCALENDARCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcalendarcore
