# $NetBSD: buildlink3.mk,v 1.31 2026/05/09 13:03:11 vins Exp $

BUILDLINK_TREE+=	librest

.if !defined(LIBREST_BUILDLINK3_MK)
LIBREST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librest+=	librest>=0.10
BUILDLINK_ABI_DEPENDS.librest+=	librest>=0.10.2
BUILDLINK_PKGSRCDIR.librest?=	../../www/librest

BUILDLINK_INCDIRS.librest?=	include/rest-1.0/rest \
				include/rest-1.0/rest-extras
BUILDLINK_LIBNAME.librest=     tirpc
BUILDLINK_LIBS.librest=        ${BUILDLINK_LIBNAME.librest:S/^/-l/:S/^-l$//}

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtksourceview5/buildlink3.mk"
.endif	# LIBREST_BUILDLINK3_MK

BUILDLINK_TREE+=	-librest
