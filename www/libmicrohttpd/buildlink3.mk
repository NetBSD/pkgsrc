# $NetBSD: buildlink3.mk,v 1.16 2022/10/26 10:31:09 wiz Exp $

BUILDLINK_TREE+=	libmicrohttpd

.if !defined(LIBMICROHTTPD_BUILDLINK3_MK)
LIBMICROHTTPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmicrohttpd+=	libmicrohttpd>=0.9.9
BUILDLINK_ABI_DEPENDS.libmicrohttpd+=	libmicrohttpd>=0.9.75nb1
BUILDLINK_PKGSRCDIR.libmicrohttpd?=	../../www/libmicrohttpd

.include "../../security/gnutls/buildlink3.mk"
.endif # LIBMICROHTTPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmicrohttpd
