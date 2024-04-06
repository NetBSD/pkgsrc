# $NetBSD: buildlink3.mk,v 1.51 2024/04/06 08:06:53 wiz Exp $

BUILDLINK_TREE+=	libmediawiki

.if !defined(LIBMEDIAWIKI_BUILDLINK3_MK)
LIBMEDIAWIKI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmediawiki+=	libmediawiki>=5.37.0
BUILDLINK_ABI_DEPENDS.libmediawiki?=	libmediawiki>=5.37.0nb19
BUILDLINK_PKGSRCDIR.libmediawiki?=	../../www/libmediawiki

.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBMEDIAWIKI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmediawiki
