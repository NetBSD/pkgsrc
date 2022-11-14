# $NetBSD: buildlink3.mk,v 1.5 2022/11/14 19:29:13 tnn Exp $

BUILDLINK_TREE+=	varnish

.if !defined(VARNISH_BUILDLINK3_MK)
VARNISH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.varnish+=	varnish>=7.2.1
BUILDLINK_PKGSRCDIR.varnish?=	../../www/varnish

BUILDLINK_INCDIRS.varnish+=	include/varnish

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"

.endif	# VARNISH_BUILDLINK3_MK

BUILDLINK_TREE+=	-varnish
