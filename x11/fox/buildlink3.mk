# $NetBSD: buildlink3.mk,v 1.35 2023/01/03 17:36:35 wiz Exp $

BUILDLINK_TREE+=	fox

.if !defined(FOX_BUILDLINK3_MK)
FOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fox+=	fox>=1.6.25
BUILDLINK_ABI_DEPENDS.fox+=	fox>=1.6.57nb3
BUILDLINK_PKGSRCDIR.fox?=	../../x11/fox
BUILDLINK_INCDIRS.fox?=		include/fox-1.6

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.endif # FOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-fox
