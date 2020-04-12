# $NetBSD: buildlink3.mk,v 1.17 2020/04/12 08:28:11 adam Exp $

BUILDLINK_TREE+=	kitemviews

.if !defined(KITEMVIEWS_BUILDLINK3_MK)
KITEMVIEWS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kitemviews+=	kitemviews>=5.18.0
BUILDLINK_ABI_DEPENDS.kitemviews?=	kitemviews>=5.66.0nb3
BUILDLINK_PKGSRCDIR.kitemviews?=	../../x11/kitemviews

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KITEMVIEWS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kitemviews
