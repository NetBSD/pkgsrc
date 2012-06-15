# $NetBSD: options.mk,v 1.4 2012/06/15 23:06:02 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fltk2
PKG_SUPPORTED_OPTIONS=	opengl
PKG_SUGGESTED_OPTIONS=

# Default
.if ${MACHINE_ARCH} != "m68k" && ${MACHINE_ARCH} != "m68000" && \
	${MACHINE_ARCH} != "vax"
PKG_SUGGESTED_OPTIONS+=	opengl
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	opengl
.if !empty(PKG_OPTIONS:Mopengl)
PLIST.opengl=	yes
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gl
SUBST_CLASSES+=		opengl
SUBST_STAGE.opengl=	post-configure
SUBST_FILES.opengl=	Makefile
SUBST_SED.opengl=	-e 's|OpenGL fluid glut test|fluid|g'
.endif
