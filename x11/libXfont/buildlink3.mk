# $NetBSD: buildlink3.mk,v 1.6 2013/06/04 22:17:27 tron Exp $

BUILDLINK_TREE+=	libXfont

.if !defined(LIBXFONT_BUILDLINK3_MK)
LIBXFONT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXfont+=	libXfont>=1.2.0
BUILDLINK_ABI_DEPENDS.libXfont+=	libXfont>=1.4.5nb2
BUILDLINK_PKGSRCDIR.libXfont?=	../../x11/libXfont

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # LIBXFONT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXfont
