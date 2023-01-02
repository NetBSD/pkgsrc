# $NetBSD: buildlink3.mk,v 1.32 2023/01/02 00:11:17 wiz Exp $

BUILDLINK_TREE+=	librest

.if !defined(LIBREST_BUILDLINK3_MK)
LIBREST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librest+=	librest07>=0.7
BUILDLINK_ABI_DEPENDS.librest+=	librest07>=0.7.93nb21
BUILDLINK_PKGSRCDIR.librest?=	../../www/librest07

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBREST_BUILDLINK3_MK

BUILDLINK_TREE+=	-librest
