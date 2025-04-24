# $NetBSD: buildlink3.mk,v 1.22 2025/04/24 14:16:09 wiz Exp $

BUILDLINK_TREE+=	fltk13

.if !defined(FLTK13_BUILDLINK3_MK)
FLTK13_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fltk13+=	fltk13>=1.3.0<1.4.0
BUILDLINK_ABI_DEPENDS.fltk13?=	fltk13>=1.3.11nb2
BUILDLINK_PKGSRCDIR.fltk13?=	../../x11/fltk13
BUILDLINK_FILES.fltk13+=	include/Fl/*

pkgbase := fltk13
.include "../../mk/pkg-build-options.mk"

# For "opengl" option
.if ${PKG_BUILD_OPTIONS.fltk13:Mopengl}
.  if ${OPSYS} != "Darwin"
.    include "../../graphics/MesaLib/buildlink3.mk"
.    include "../../graphics/glu/buildlink3.mk"
.  endif
.endif

.if ${OPSYS} != "Darwin"
.  include "../../x11/libXcursor/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXft/buildlink3.mk"
.  include "../../x11/libXinerama/buildlink3.mk"
.  include "../../fonts/fontconfig/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXrender/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # FLTK13_BUILDLINK3_MK

BUILDLINK_TREE+=	-fltk13
