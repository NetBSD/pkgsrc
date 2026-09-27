# $NetBSD: buildlink3.mk,v 1.42 2026/09/27 11:39:06 tnn Exp $

BUILDLINK_TREE+=	kjs

.if !defined(KJS_BUILDLINK3_MK)
KJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kjs+=	kjs>=5.21.0
BUILDLINK_ABI_DEPENDS.kjs?=	kjs>=5.116.0nb9
BUILDLINK_PKGSRCDIR.kjs?=	../../www/kjs

BUILDLINK_FILES.kjs+=		share/kf5/kjs/create_hash_table

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kjs
