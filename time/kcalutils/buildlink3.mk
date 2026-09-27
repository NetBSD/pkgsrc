# $NetBSD: buildlink3.mk,v 1.47 2026/09/27 11:38:56 tnn Exp $

BUILDLINK_TREE+=	kcalutils

.if !defined(KCALUTILS_BUILDLINK3_MK)
KCALUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcalutils+=	kcalutils>=25.08.2
BUILDLINK_ABI_DEPENDS.kcalutils?=	kcalutils>=26.08.0nb1
BUILDLINK_PKGSRCDIR.kcalutils?=		../../time/kcalutils

.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../textproc/kf6-ktexttemplate/buildlink3.mk"
.include "../../time/kf6-kcalendarcore/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KCALUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcalutils
