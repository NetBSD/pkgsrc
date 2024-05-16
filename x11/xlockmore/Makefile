# $NetBSD: Makefile,v 1.179 2024/05/16 06:15:47 wiz Exp $

#PKGREVISION= 1
PKGREVISION= 1
.include "Makefile.common"

COMMENT=	Like the XLock session-locker/screensaver, but with more

CONFLICTS+=	xlockmore-lite-[0-9]*

CONFIGURE_ARGS+=	--with-opengl
CONFIGURE_ARGS+=	--with-mesa
CONFIGURE_ARGS+=	--without-ftgl
CONFIGURE_ARGS+=	--without-ttf
XPM_ENV=		no_xpm= xpm_includes=${BUILDLINK_PREFIX.libXpm}/include xpm_libraries=${BUILDLINK_PREFIX.libXpm}/lib
CONFIGURE_ENV+=		ac_cv_path_xpm=${XPM_ENV:Q}
OPENGL_ENV=		no_opengl= ac_opengl_includes=${BUILDLINK_PREFIX.MesaLib}/include ac_opengl_libraries=${BUILDLINK_PREFIX.MesaLib}/lib
CONFIGURE_ENV+=		ac_cv_path_opengl=${OPENGL_ENV:Q}
MESA_ENV=		no_mesa= ac_mesa_includes=${BUILDLINK_PREFIX.MesaLib}/include ac_mesa_libraries=${BUILDLINK_PREFIX.MesaLib}/lib
CONFIGURE_ENV+=		ac_cv_path_mesa=${MESA_ENV:Q}
#BUILDLINK_TRANSFORM+=	l:MesaGL:GL
#BUILDLINK_TRANSFORM+=	l:MesaGLU:GLU
XEXT_ENV=		no_ext= ac_ext_includes=${BUILDLINK_PREFIX.xorgproto}/include ac_ext_libraries=${BUILDLINK_PREFIX.libXext}/lib
CONFIGURE_ENV+=		ac_cv_path_ext=${XEXT_ENV:Q}

PLIST_SUBST+=	LITE=""

USE_TOOLS+=	pkg-config

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
