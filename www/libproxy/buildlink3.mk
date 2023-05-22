# $NetBSD: buildlink3.mk,v 1.8 2023/05/22 21:00:09 wiz Exp $

BUILDLINK_TREE+=	libproxy

.if !defined(LIBPROXY_BUILDLINK3_MK)
LIBPROXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libproxy+=	libproxy>=0.2.3
BUILDLINK_ABI_DEPENDS.libproxy+=	libproxy>=0.5.0
BUILDLINK_PKGSRCDIR.libproxy?=		../../www/libproxy

# before version 0.5, the header file was directly in include/proxy.h
BUILDLINK_FNAME_TRANSFORM.libproxy+=	-e s,include/libproxy,include,

.include "../../devel/glib2/buildlink3.mk"
.endif # LIBPROXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libproxy
