# $NetBSD: buildlink3.mk,v 1.18 2014/05/15 14:41:59 adam Exp $

BUILDLINK_TREE+=	libmediawiki

.if !defined(LIBMEDIAWIKI_BUILDLINK3_MK)
LIBMEDIAWIKI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmediawiki+=	libmediawiki>=2.5.0
BUILDLINK_ABI_DEPENDS.libmediawiki?=	libmediawiki>=3.5.0nb4
BUILDLINK_PKGSRCDIR.libmediawiki?=	../../www/libmediawiki

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBMEDIAWIKI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmediawiki
