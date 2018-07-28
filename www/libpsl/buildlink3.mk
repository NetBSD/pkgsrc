# $NetBSD: buildlink3.mk,v 1.1 2018/07/28 12:25:20 bsiegert Exp $

BUILDLINK_TREE+=	libpsl

.if !defined(LIBPSL_BUILDLINK3_MK)
LIBPSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpsl+=	libpsl>=0.20.2
BUILDLINK_PKGSRCDIR.libpsl?=	../../www/libpsl

#.include "../../textproc/icu/buildlink3.mk"
.endif	# LIBPSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpsl
