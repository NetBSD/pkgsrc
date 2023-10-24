# $NetBSD: buildlink3.mk,v 1.25 2023/10/24 22:11:28 wiz Exp $

BUILDLINK_TREE+=	libmrss

.if !defined(LIBMRSS_BUILDLINK3_MK)
LIBMRSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmrss+=	libmrss>=0.19.2
BUILDLINK_ABI_DEPENDS.libmrss+=	libmrss>=0.19.2nb27
BUILDLINK_PKGSRCDIR.libmrss?=	../../www/libmrss

.include "../../textproc/libnxml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# LIBMRSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmrss
