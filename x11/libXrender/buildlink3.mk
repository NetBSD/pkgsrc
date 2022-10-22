# $NetBSD: buildlink3.mk,v 1.9 2022/10/22 16:54:53 wiz Exp $

BUILDLINK_TREE+=	libXrender

.if !defined(LIBXRENDER_BUILDLINK3_MK)
LIBXRENDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXrender+=	libXrender>=0.9.2
BUILDLINK_PKGSRCDIR.libXrender?=	../../x11/libXrender

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # LIBXRENDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXrender
