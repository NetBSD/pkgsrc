# $NetBSD: buildlink3.mk,v 1.6 2017/09/18 09:53:06 maya Exp $

BUILDLINK_TREE+=	kjs

.if !defined(KJS_BUILDLINK3_MK)
KJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kjs+=	kjs>=5.21.0
BUILDLINK_ABI_DEPENDS.kjs?=	kjs>=5.25.0nb5
BUILDLINK_PKGSRCDIR.kjs?=	../../www/kjs

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kjs
