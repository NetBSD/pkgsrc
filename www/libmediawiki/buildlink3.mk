# $NetBSD: buildlink3.mk,v 1.47 2023/05/22 21:00:09 wiz Exp $

BUILDLINK_TREE+=	libmediawiki

.if !defined(LIBMEDIAWIKI_BUILDLINK3_MK)
LIBMEDIAWIKI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmediawiki+=	libmediawiki>=5.37.0
BUILDLINK_ABI_DEPENDS.libmediawiki?=	libmediawiki>=5.37.0nb15
BUILDLINK_PKGSRCDIR.libmediawiki?=	../../www/libmediawiki

.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBMEDIAWIKI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmediawiki
