# $NetBSD: buildlink3.mk,v 1.37 2022/07/02 16:53:39 ryoon Exp $

BUILDLINK_TREE+=	kactivities5

.if !defined(KACTIVITIES5_BUILDLINK3_MK)
KACTIVITIES5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kactivities5+=	kactivities5>=5.21.0
BUILDLINK_ABI_DEPENDS.kactivities5?=	kactivities5>=5.93.0nb1
BUILDLINK_PKGSRCDIR.kactivities5?=	../../x11/kactivities5

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KACTIVITIES5_BUILDLINK3_MK

BUILDLINK_TREE+=	-kactivities5
