# $NetBSD: buildlink3.mk,v 1.24 2025/04/17 21:52:48 wiz Exp $

BUILDLINK_TREE+=	libmicrohttpd

.if !defined(LIBMICROHTTPD_BUILDLINK3_MK)
LIBMICROHTTPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmicrohttpd+=	libmicrohttpd>=0.9.9
BUILDLINK_ABI_DEPENDS.libmicrohttpd+=	libmicrohttpd>=1.0.1nb6
BUILDLINK_PKGSRCDIR.libmicrohttpd?=	../../www/libmicrohttpd

.include "../../security/gnutls/buildlink3.mk"
.endif # LIBMICROHTTPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmicrohttpd
