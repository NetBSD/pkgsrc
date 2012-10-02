# $NetBSD: buildlink3.mk,v 1.3 2012/10/02 12:09:41 tron Exp $

BUILDLINK_TREE+=	libxcb

.if !defined(LIBXCB_BUILDLINK3_MK)
LIBXCB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.6
BUILDLINK_ABI_DEPENDS.libxcb+=	libxcb>=1.6
BUILDLINK_PKGSRCDIR.libxcb?=	../../x11/libxcb

.include "../../x11/xcb-proto/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.endif # LIBXCB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxcb
