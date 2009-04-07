# $NetBSD: buildlink3.mk,v 1.3 2009/04/07 03:14:07 dsainty Exp $

BUILDLINK_TREE+=	libproxy

.if !defined(LIBPROXY_BUILDLINK3_MK)
LIBPROXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libproxy+=	libproxy>=0.2.3
BUILDLINK_PKGSRCDIR.libproxy?=	../../www/libproxy

.include "../../lang/python/extension.mk"

.endif # LIBPROXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libproxy
