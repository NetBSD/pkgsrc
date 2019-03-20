# $NetBSD: buildlink3.mk,v 1.1 2019/03/20 12:04:14 wiz Exp $

BUILDLINK_TREE+=	libdmx

.if !defined(LIBDMX_BUILDLINK3_MK)
LIBDMX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdmx+=	libdmx>=1.1.4
BUILDLINK_PKGSRCDIR.libdmx?=	../../x11/libdmx

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.endif # LIBDMX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdmx
