# $NetBSD: buildlink3.mk,v 1.2 2012/05/07 02:45:47 dholland Exp $

BUILDLINK_TREE+=	libxcb

.if !defined(LIBXCB_BUILDLINK3_MK)
LIBXCB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.1.93
BUILDLINK_PKGSRCDIR.libxcb?=	../../x11/libxcb

.include "../../x11/xcb-proto/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.endif # LIBXCB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxcb
