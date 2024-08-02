# $NetBSD: buildlink3.mk,v 1.6 2024/08/02 07:05:03 wiz Exp $

BUILDLINK_TREE+=	libXfont2

.if !defined(LIBXFONT2_BUILDLINK3_MK)
LIBXFONT2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXfont2+=	libXfont2>=2.0
BUILDLINK_ABI_DEPENDS.libXfont2?=	libXfont2>=2.0.6nb2
BUILDLINK_PKGSRCDIR.libXfont2?=		../../x11/libXfont2

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.endif # LIBXFONT2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXfont2
