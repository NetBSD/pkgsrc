# $NetBSD: buildlink3.mk,v 1.35 2024/11/01 12:54:51 wiz Exp $

BUILDLINK_TREE+=	kjs

.if !defined(KJS_BUILDLINK3_MK)
KJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kjs+=	kjs>=5.21.0
BUILDLINK_ABI_DEPENDS.kjs?=	kjs>=5.116.0nb2
BUILDLINK_PKGSRCDIR.kjs?=	../../www/kjs

BUILDLINK_FILES.kjs+=		share/kf5/kjs/create_hash_table

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kjs
