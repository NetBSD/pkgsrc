# $NetBSD: buildlink3.mk,v 1.9 2014/01/01 11:52:07 wiz Exp $

BUILDLINK_TREE+=	librest

.if !defined(LIBREST_BUILDLINK3_MK)
LIBREST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librest+=	librest07>=0.7
BUILDLINK_ABI_DEPENDS.librest+=	librest07>=0.7.12nb8
BUILDLINK_PKGSRCDIR.librest?=	../../www/librest07

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBREST_BUILDLINK3_MK

BUILDLINK_TREE+=	-librest
