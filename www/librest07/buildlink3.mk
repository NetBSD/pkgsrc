# $NetBSD: buildlink3.mk,v 1.12 2015/04/06 08:17:17 adam Exp $

BUILDLINK_TREE+=	librest

.if !defined(LIBREST_BUILDLINK3_MK)
LIBREST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librest+=	librest07>=0.7
BUILDLINK_ABI_DEPENDS.librest+=	librest07>=0.7.92nb1
BUILDLINK_PKGSRCDIR.librest?=	../../www/librest07

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBREST_BUILDLINK3_MK

BUILDLINK_TREE+=	-librest
