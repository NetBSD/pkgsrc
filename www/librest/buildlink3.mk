# $NetBSD: buildlink3.mk,v 1.27 2018/12/09 18:52:10 adam Exp $

BUILDLINK_TREE+=	librest

.if !defined(LIBREST_BUILDLINK3_MK)
LIBREST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librest+=	librest>=0.6
BUILDLINK_ABI_DEPENDS.librest+=	librest>=0.6nb27
BUILDLINK_PKGSRCDIR.librest?=	../../www/librest

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBREST_BUILDLINK3_MK

BUILDLINK_TREE+=	-librest
