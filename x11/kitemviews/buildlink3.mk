# $NetBSD: buildlink3.mk,v 1.26 2023/04/19 08:08:53 adam Exp $

BUILDLINK_TREE+=	kitemviews

.if !defined(KITEMVIEWS_BUILDLINK3_MK)
KITEMVIEWS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kitemviews+=	kitemviews>=5.18.0
BUILDLINK_ABI_DEPENDS.kitemviews?=	kitemviews>=5.98.0nb4
BUILDLINK_PKGSRCDIR.kitemviews?=	../../x11/kitemviews

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KITEMVIEWS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kitemviews
