# $NetBSD: buildlink3.mk,v 1.3 2022/01/09 02:55:08 tnn Exp $

BUILDLINK_TREE+=	varnish

.if !defined(VARNISH_BUILDLINK3_MK)
VARNISH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.varnish+=	varnish>=7.0.1
BUILDLINK_PKGSRCDIR.varnish?=	../../www/varnish

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"

.endif	# VARNISH_BUILDLINK3_MK

BUILDLINK_TREE+=	-varnish
