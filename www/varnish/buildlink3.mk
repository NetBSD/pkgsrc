# $NetBSD: buildlink3.mk,v 1.2 2021/06/25 12:21:08 tnn Exp $

BUILDLINK_TREE+=	varnish

.if !defined(VARNISH_BUILDLINK3_MK)
VARNISH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.varnish+=	varnish>=6.6.0
BUILDLINK_PKGSRCDIR.varnish?=	../../www/varnish

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"

.endif	# VARNISH_BUILDLINK3_MK

BUILDLINK_TREE+=	-varnish
