# $NetBSD: buildlink3.mk,v 1.10 2023/11/12 13:24:13 wiz Exp $

BUILDLINK_TREE+=	libXfont

.if !defined(LIBXFONT_BUILDLINK3_MK)
LIBXFONT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXfont+=	libXfont>=1.2.0
BUILDLINK_ABI_DEPENDS.libXfont+=	libXfont>=1.5.4nb4
BUILDLINK_PKGSRCDIR.libXfont?=		../../x11/libXfont

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.endif # LIBXFONT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXfont
