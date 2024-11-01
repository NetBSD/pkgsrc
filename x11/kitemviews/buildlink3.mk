# $NetBSD: buildlink3.mk,v 1.33 2024/11/01 12:55:05 wiz Exp $

BUILDLINK_TREE+=	kitemviews

.if !defined(KITEMVIEWS_BUILDLINK3_MK)
KITEMVIEWS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kitemviews+=	kitemviews>=5.18.0
BUILDLINK_ABI_DEPENDS.kitemviews?=	kitemviews>=5.116.0nb2
BUILDLINK_PKGSRCDIR.kitemviews?=	../../x11/kitemviews

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KITEMVIEWS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kitemviews
