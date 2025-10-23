# $NetBSD: buildlink3.mk,v 1.10 2025/10/23 20:39:47 wiz Exp $

BUILDLINK_TREE+=	libproxy

.if !defined(LIBPROXY_BUILDLINK3_MK)
LIBPROXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libproxy+=	libproxy>=0.2.3
BUILDLINK_ABI_DEPENDS.libproxy+=	libproxy>=0.5.11nb2
BUILDLINK_PKGSRCDIR.libproxy?=		../../www/libproxy

BUILDLINK_INCDIRS.libproxy+=		include/libroxy

.include "../../devel/glib2/buildlink3.mk"
.endif # LIBPROXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libproxy
