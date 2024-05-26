# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 13:36:44 markd Exp $

BUILDLINK_TREE+=	kf6-kitemviews

.if !defined(KF6_KITEMVIEWS_BUILDLINK3_MK)
KF6_KITEMVIEWS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kitemviews+=	kf6-kitemviews>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kitemviews?=	../../x11/kf6-kitemviews

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KITEMVIEWS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kitemviews
