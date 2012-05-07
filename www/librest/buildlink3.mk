# $NetBSD: buildlink3.mk,v 1.7 2012/05/07 01:54:05 dholland Exp $

BUILDLINK_TREE+=	librest

.if !defined(LIBREST_BUILDLINK3_MK)
LIBREST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librest+=	librest>=0.6
BUILDLINK_ABI_DEPENDS.librest+=	librest>=0.6nb5
BUILDLINK_PKGSRCDIR.librest?=	../../www/librest

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBREST_BUILDLINK3_MK

BUILDLINK_TREE+=	-librest
