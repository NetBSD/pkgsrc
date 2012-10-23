# $NetBSD: buildlink3.mk,v 1.6 2012/10/23 10:24:19 wiz Exp $

BUILDLINK_TREE+=	libXv

.if !defined(LIBXV_BUILDLINK3_MK)
LIBXV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXv+=	libXv>=1.0.1
BUILDLINK_PKGSRCDIR.libXv?=	../../x11/libXv

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # LIBXV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXv
