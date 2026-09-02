# $NetBSD: buildlink3.mk,v 1.11 2026/09/02 19:04:59 wiz Exp $

BUILDLINK_TREE+=	libproxy

.if !defined(LIBPROXY_BUILDLINK3_MK)
LIBPROXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libproxy+=	libproxy>=0.2.3
BUILDLINK_ABI_DEPENDS.libproxy+=	libproxy>=0.5.12nb4
BUILDLINK_PKGSRCDIR.libproxy?=		../../www/libproxy

BUILDLINK_INCDIRS.libproxy+=		include/libroxy

.include "../../devel/glib2/buildlink3.mk"
.endif # LIBPROXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libproxy
