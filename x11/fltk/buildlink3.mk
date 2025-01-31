# $NetBSD: buildlink3.mk,v 1.29 2025/01/31 12:22:44 micha Exp $

BUILDLINK_TREE+=	fltk

.if !defined(FLTK_BUILDLINK3_MK)
FLTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fltk+=	fltk>=1.4.1<1.5.0
BUILDLINK_PKGSRCDIR.fltk?=	../../x11/fltk
BUILDLINK_FILES.fltk+=		include/Fl/*

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := fltk
.include "../../mk/pkg-build-options.mk"

# For "cairo" option
.if ${PKG_BUILD_OPTIONS.fltk:Mcairo}
.  include "../../graphics/cairo/buildlink3.mk"
.endif

# For "opengl" option
.if ${PKG_BUILD_OPTIONS.fltk:Mopengl}
.  if ${PKG_BUILD_OPTIONS.fltk:Mx11}
.    include "../../graphics/MesaLib/buildlink3.mk"
.    include "../../graphics/glu/buildlink3.mk"
.  endif
.endif

# For "pango" option
.if ${PKG_BUILD_OPTIONS.fltk:Mpango}
.  if ${PKG_BUILD_OPTIONS.fltk:Mx11}
.    include "../../devel/pango/buildlink3.mk"
.  endif
.endif

# For "wayland" option
.if ${PKG_BUILD_OPTIONS.fltk:Mwayland}
.  include "../../devel/wayland/buildlink3.mk"
.endif

# For "x11" option
.if ${PKG_BUILD_OPTIONS.fltk:Mx11}
.  include "../../x11/libX11/buildlink3.mk"
.endif

# For "xcursor" option
.if ${PKG_BUILD_OPTIONS.fltk:Mxcursor}
.  if ${PKG_BUILD_OPTIONS.fltk:Mx11}
.    include "../../x11/libXcursor/buildlink3.mk"
.  endif
.endif

# For "xfixes" option
.if ${PKG_BUILD_OPTIONS.fltk:Mxfixes}
.  if ${PKG_BUILD_OPTIONS.fltk:Mx11}
.    include "../../x11/libXfixes/buildlink3.mk"
.  endif
.endif

# For "xft2" option
.if ${PKG_BUILD_OPTIONS.fltk:Mxft2}
.  if ${PKG_BUILD_OPTIONS.fltk:Mx11}
.    include "../../x11/libXft/buildlink3.mk"
.  endif
.endif

# For "xinerama" option
.if ${PKG_BUILD_OPTIONS.fltk:Mxinerama}
.  if ${PKG_BUILD_OPTIONS.fltk:Mx11}
.    include "../../x11/libXinerama/buildlink3.mk"
.  endif
.endif

# For "xrender" option
.if ${PKG_BUILD_OPTIONS.fltk:Mxrender}
.  if ${PKG_BUILD_OPTIONS.fltk:Mx11}
.    include "../../x11/libXrender/buildlink3.mk"
.  endif
.endif

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif # FLTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-fltk
