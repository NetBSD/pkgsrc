# $NetBSD: buildlink3.mk,v 1.14 2018/03/12 11:15:52 wiz Exp $

BUILDLINK_TREE+=	kactivities5

.if !defined(KACTIVITIES5_BUILDLINK3_MK)
KACTIVITIES5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kactivities5+=	kactivities5>=5.21.0
BUILDLINK_ABI_DEPENDS.kactivities5?=	kactivities5>=5.41.0nb3
BUILDLINK_PKGSRCDIR.kactivities5?=	../../x11/kactivities5

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KACTIVITIES5_BUILDLINK3_MK

BUILDLINK_TREE+=	-kactivities5
