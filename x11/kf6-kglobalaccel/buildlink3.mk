# $NetBSD: buildlink3.mk,v 1.3 2024/11/01 12:55:03 wiz Exp $

BUILDLINK_TREE+=	kf6-kglobalaccel

.if !defined(KF6_KGLOBALACCEL_BUILDLINK3_MK)
KF6_KGLOBALACCEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kglobalaccel+=	kf6-kglobalaccel>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kglobalaccel?=		kf6-kglobalaccel>=6.2.0nb3
BUILDLINK_PKGSRCDIR.kf6-kglobalaccel?=		../../x11/kf6-kglobalaccel

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KGLOBALACCEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kglobalaccel
