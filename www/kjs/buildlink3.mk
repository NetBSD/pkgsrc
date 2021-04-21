# $NetBSD: buildlink3.mk,v 1.21 2021/04/21 11:40:43 adam Exp $

BUILDLINK_TREE+=	kjs

.if !defined(KJS_BUILDLINK3_MK)
KJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kjs+=	kjs>=5.21.0
BUILDLINK_ABI_DEPENDS.kjs?=	kjs>=5.80.0nb1
BUILDLINK_PKGSRCDIR.kjs?=	../../www/kjs

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kjs
