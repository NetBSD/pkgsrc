# $NetBSD: options.mk,v 1.5 2014/08/03 22:30:05 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.webkit-gtk
PKG_SUPPORTED_OPTIONS=	debug enchant opengl webkit-jit
PKG_SUGGESTED_OPTIONS=	enchant opengl

.include "../../mk/bsd.prefs.mk"

# XXX JIT produces invalid code on NetBSD/i386 and NetBSD/amd64
.if empty(MACHINE_PLATFORM:MNetBSD-*-i386) && empty(MACHINE_PLATFORM:MNetBSD-*-x86_64)
PKG_SUGGESTED_OPTIONS+= webkit-jit
.endif

.include "../../mk/bsd.options.mk"

#
# JIT support
#
.if !empty(PKG_OPTIONS:Mwebkit-jit)
CONFIGURE_ARGS+=	--enable-jit
.else
CONFIGURE_ARGS+=	--disable-jit
.endif

#
# debug support
#
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

#
# OpenGL support: enable support for GLX, WebGL and accelerated compositing
#
# TODO: should we split them in multiple options?
#
.if !empty(PKG_OPTIONS:Mopengl)
CONFIGURE_ARGS+=	--enable-glx
CONFIGURE_ARGS+=	--enable-webgl
CONFIGURE_ARGS+=	--enable-accelerated-compositing
.else
CONFIGURE_ARGS+=	--disable-glx
CONFIGURE_ARGS+=	--disable-webgl
CONFIGURE_ARGS+=	--disable-accelerated-compositing
.endif

#
# Spellcheck support using enchant
#
.if !empty(PKG_OPTIONS:Menchant)
CONFIGURE_ARGS+=	--enable-spellcheck
.include "../../textproc/enchant/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-spellcheck
.endif
