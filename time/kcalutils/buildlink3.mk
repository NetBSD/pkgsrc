# $NetBSD: buildlink3.mk,v 1.40 2026/01/07 08:49:11 wiz Exp $

BUILDLINK_TREE+=	kcalutils

.if !defined(KCALUTILS_BUILDLINK3_MK)
KCALUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcalutils+=	kcalutils>=25.08.2
BUILDLINK_ABI_DEPENDS.kcalutils?=	kcalutils>=25.08.3nb1
BUILDLINK_PKGSRCDIR.kcalutils?=		../../time/kcalutils

.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../textproc/kf6-ktexttemplate/buildlink3.mk"
.include "../../time/kf6-kcalendarcore/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KCALUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcalutils
