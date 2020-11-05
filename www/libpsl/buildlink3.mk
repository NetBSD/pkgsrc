# $NetBSD: buildlink3.mk,v 1.8 2020/11/05 09:07:13 ryoon Exp $

BUILDLINK_TREE+=	libpsl

.if !defined(LIBPSL_BUILDLINK3_MK)
LIBPSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpsl+=	libpsl>=0.20.2
BUILDLINK_ABI_DEPENDS.libpsl+=	libpsl>=0.21.1nb1
BUILDLINK_PKGSRCDIR.libpsl?=	../../www/libpsl

.include "../../textproc/icu/buildlink3.mk"
.endif	# LIBPSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpsl
