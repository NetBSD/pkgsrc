# $NetBSD: buildlink3.mk,v 1.30 2024/11/14 22:22:06 wiz Exp $

BUILDLINK_TREE+=	libmrss

.if !defined(LIBMRSS_BUILDLINK3_MK)
LIBMRSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmrss+=	libmrss>=0.19.2
BUILDLINK_ABI_DEPENDS.libmrss+=	libmrss>=0.19.2nb33
BUILDLINK_PKGSRCDIR.libmrss?=	../../www/libmrss

.include "../../textproc/libnxml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# LIBMRSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmrss
