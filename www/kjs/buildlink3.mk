# $NetBSD: buildlink3.mk,v 1.32 2023/11/12 13:23:55 wiz Exp $

BUILDLINK_TREE+=	kjs

.if !defined(KJS_BUILDLINK3_MK)
KJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kjs+=	kjs>=5.21.0
BUILDLINK_ABI_DEPENDS.kjs?=	kjs>=5.108.0nb3
BUILDLINK_PKGSRCDIR.kjs?=	../../www/kjs

BUILDLINK_FILES.kjs+=		share/kf5/kjs/create_hash_table

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kjs
