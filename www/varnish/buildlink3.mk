# $NetBSD: buildlink3.mk,v 1.4 2022/09/23 09:07:23 wiz Exp $

BUILDLINK_TREE+=	varnish

.if !defined(VARNISH_BUILDLINK3_MK)
VARNISH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.varnish+=	varnish>=7.0.1
BUILDLINK_PKGSRCDIR.varnish?=	../../www/varnish

BUILDLINK_INCDIRS.varnish+=	include/varnish

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"

.endif	# VARNISH_BUILDLINK3_MK

BUILDLINK_TREE+=	-varnish
