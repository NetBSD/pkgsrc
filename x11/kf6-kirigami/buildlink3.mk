# $NetBSD: buildlink3.mk,v 1.2 2024/11/01 00:54:16 wiz Exp $

BUILDLINK_TREE+=	kf6-kirigami

.if !defined(KF6_KIRIGAMI_BUILDLINK3_MK)
KF6_KIRIGAMI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kirigami+=	kf6-kirigami>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kirigami?=	kf6-kirigami>=6.2.0nb2
BUILDLINK_PKGSRCDIR.kf6-kirigami?=	../../x11/kf6-kirigami

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KIRIGAMI_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kirigami
