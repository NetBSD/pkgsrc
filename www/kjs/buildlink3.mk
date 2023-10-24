# $NetBSD: buildlink3.mk,v 1.30 2023/10/24 22:11:28 wiz Exp $

BUILDLINK_TREE+=	kjs

.if !defined(KJS_BUILDLINK3_MK)
KJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kjs+=	kjs>=5.21.0
BUILDLINK_ABI_DEPENDS.kjs?=	kjs>=5.108.0nb1
BUILDLINK_PKGSRCDIR.kjs?=	../../www/kjs

BUILDLINK_FILES.kjs+=		share/kf5/kjs/create_hash_table

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kjs
