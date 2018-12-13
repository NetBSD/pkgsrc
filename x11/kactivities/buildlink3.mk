# $NetBSD: buildlink3.mk,v 1.32 2018/12/13 19:51:39 adam Exp $

BUILDLINK_TREE+=	kactivities

.if !defined(KACTIVITIES_BUILDLINK3_MK)
KACTIVITIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kactivities+=	kactivities>=4.7.95
BUILDLINK_ABI_DEPENDS.kactivities+=	kactivities>=4.13.3nb13
BUILDLINK_PKGSRCDIR.kactivities?=	../../x11/kactivities

.include "../../x11/kdelibs4/buildlink3.mk"
.endif # KACTIVITIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-kactivities
