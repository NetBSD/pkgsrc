# $NetBSD: buildlink3.mk,v 1.17 2017/04/22 21:03:18 adam Exp $

BUILDLINK_TREE+=	librest

.if !defined(LIBREST_BUILDLINK3_MK)
LIBREST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librest+=	librest07>=0.7
BUILDLINK_ABI_DEPENDS.librest+=	librest07>=0.7.93nb5
BUILDLINK_PKGSRCDIR.librest?=	../../www/librest07

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBREST_BUILDLINK3_MK

BUILDLINK_TREE+=	-librest
