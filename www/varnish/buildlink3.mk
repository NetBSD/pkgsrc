# $NetBSD: buildlink3.mk,v 1.8 2026/09/02 19:05:02 wiz Exp $

BUILDLINK_TREE+=	varnish

.if !defined(VARNISH_BUILDLINK3_MK)
VARNISH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.varnish+=	varnish>=7.2.1
BUILDLINK_ABI_DEPENDS.varnish?=	varnish>=7.7.1nb2
BUILDLINK_PKGSRCDIR.varnish?=	../../www/varnish

BUILDLINK_INCDIRS.varnish+=	include/varnish

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"

.endif	# VARNISH_BUILDLINK3_MK

BUILDLINK_TREE+=	-varnish
