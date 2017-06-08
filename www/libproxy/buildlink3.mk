# $NetBSD: buildlink3.mk,v 1.6 2017/06/08 11:27:05 adam Exp $

BUILDLINK_TREE+=	libproxy

.if !defined(LIBPROXY_BUILDLINK3_MK)
LIBPROXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libproxy+=	libproxy>=0.2.3
BUILDLINK_ABI_DEPENDS.libproxy+=	libproxy>=0.4.11
BUILDLINK_PKGSRCDIR.libproxy?=		../../www/libproxy
.endif # LIBPROXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libproxy
