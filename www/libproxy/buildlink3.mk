# $NetBSD: buildlink3.mk,v 1.4 2009/09/10 02:03:11 dsainty Exp $

BUILDLINK_TREE+=	libproxy

.if !defined(LIBPROXY_BUILDLINK3_MK)
LIBPROXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libproxy+=	libproxy>=0.2.3
BUILDLINK_PKGSRCDIR.libproxy?=	../../www/libproxy
.endif # LIBPROXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libproxy
