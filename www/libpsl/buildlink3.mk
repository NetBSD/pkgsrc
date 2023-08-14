# $NetBSD: buildlink3.mk,v 1.10 2023/08/14 05:25:29 wiz Exp $

BUILDLINK_TREE+=	libpsl

.if !defined(LIBPSL_BUILDLINK3_MK)
LIBPSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpsl+=	libpsl>=0.20.2
BUILDLINK_ABI_DEPENDS.libpsl+=	libpsl>=0.21.2nb1
BUILDLINK_PKGSRCDIR.libpsl?=	../../www/libpsl
.endif	# LIBPSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpsl
