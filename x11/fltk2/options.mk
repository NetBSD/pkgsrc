# $NetBSD: options.mk,v 1.2 2009/03/14 12:10:21 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fltk2
PKG_SUPPORTED_OPTIONS=	opengl
PKG_SUGGESTED_OPTIONS=

# Default
.if ${MACHINE_ARCH} != "m68k" && ${MACHINE_ARCH} != "m68000" && \
	${MACHINE_ARCH} != "vax"
PKG_SUGGESTED_OPTIONS+=	opengl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgl)
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gl
.endif
