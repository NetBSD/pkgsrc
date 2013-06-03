# $NetBSD: buildlink3.mk,v 1.11 2013/06/03 10:06:09 wiz Exp $

BUILDLINK_TREE+=	libmediawiki

.if !defined(LIBMEDIAWIKI_BUILDLINK3_MK)
LIBMEDIAWIKI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmediawiki+=	libmediawiki>=2.5.0
BUILDLINK_ABI_DEPENDS.libmediawiki?=	libmediawiki>=3.2.0nb1
BUILDLINK_PKGSRCDIR.libmediawiki?=	../../www/libmediawiki

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBMEDIAWIKI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmediawiki
