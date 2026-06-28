# $NetBSD: buildlink3.mk,v 1.11 2026/06/28 20:07:45 wiz Exp $

BUILDLINK_TREE+=	libpsl

.if !defined(LIBPSL_BUILDLINK3_MK)
LIBPSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpsl+=	libpsl>=0.20.2
BUILDLINK_ABI_DEPENDS.libpsl+=	libpsl>=0.21.2nb1
BUILDLINK_PKGSRCDIR.libpsl?=	../../www/libpsl
.include "../../devel/libidn2/buildlink3.mk"
.endif	# LIBPSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpsl
