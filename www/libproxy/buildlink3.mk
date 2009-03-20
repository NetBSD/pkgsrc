# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:37 joerg Exp $

BUILDLINK_TREE+=	libproxy

.if !defined(LIBPROXY_BUILDLINK3_MK)
LIBPROXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libproxy+=	libproxy>=0.2.3
BUILDLINK_PKGSRCDIR.libproxy?=	../../www/libproxy
.endif # LIBPROXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libproxy
