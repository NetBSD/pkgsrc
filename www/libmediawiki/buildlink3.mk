# $NetBSD: buildlink3.mk,v 1.23 2016/03/05 11:27:57 jperkin Exp $

BUILDLINK_TREE+=	libmediawiki

.if !defined(LIBMEDIAWIKI_BUILDLINK3_MK)
LIBMEDIAWIKI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmediawiki+=	libmediawiki>=2.5.0
BUILDLINK_ABI_DEPENDS.libmediawiki?=	libmediawiki>=4.13.0nb1
BUILDLINK_PKGSRCDIR.libmediawiki?=	../../www/libmediawiki

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBMEDIAWIKI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmediawiki
