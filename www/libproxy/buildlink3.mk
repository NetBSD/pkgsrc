# $NetBSD: buildlink3.mk,v 1.2.2.1 2009/04/07 14:34:23 tron Exp $

BUILDLINK_TREE+=	libproxy

.if !defined(LIBPROXY_BUILDLINK3_MK)
LIBPROXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libproxy+=	libproxy>=0.2.3
BUILDLINK_PKGSRCDIR.libproxy?=	../../www/libproxy

.include "../../lang/python/extension.mk"

.endif # LIBPROXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libproxy
