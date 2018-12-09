# $NetBSD: buildlink3.mk,v 1.3 2018/12/09 18:52:10 adam Exp $

BUILDLINK_TREE+=	libpsl

.if !defined(LIBPSL_BUILDLINK3_MK)
LIBPSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpsl+=	libpsl>=0.20.2
BUILDLINK_ABI_DEPENDS.libpsl?=	libpsl>=0.20.2nb2
BUILDLINK_PKGSRCDIR.libpsl?=	../../www/libpsl

.include "../../textproc/icu/buildlink3.mk"
.endif	# LIBPSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpsl
