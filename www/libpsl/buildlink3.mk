# $NetBSD: buildlink3.mk,v 1.9 2020/11/07 09:27:38 nia Exp $

BUILDLINK_TREE+=	libpsl

.if !defined(LIBPSL_BUILDLINK3_MK)
LIBPSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpsl+=	libpsl>=0.20.2
BUILDLINK_ABI_DEPENDS.libpsl+=	libpsl>=0.21.1nb1
BUILDLINK_PKGSRCDIR.libpsl?=	../../www/libpsl
.endif	# LIBPSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpsl
