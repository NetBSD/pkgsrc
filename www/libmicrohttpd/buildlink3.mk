# $NetBSD: buildlink3.mk,v 1.13 2021/04/21 13:24:18 adam Exp $

BUILDLINK_TREE+=	libmicrohttpd

.if !defined(LIBMICROHTTPD_BUILDLINK3_MK)
LIBMICROHTTPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmicrohttpd+=	libmicrohttpd>=0.9.9
BUILDLINK_ABI_DEPENDS.libmicrohttpd+=	libmicrohttpd>=0.9.72nb3
BUILDLINK_PKGSRCDIR.libmicrohttpd?=	../../www/libmicrohttpd

.include "../../security/gnutls/buildlink3.mk"
.endif # LIBMICROHTTPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmicrohttpd
