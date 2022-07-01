# $NetBSD: options.mk,v 1.6 2022/07/01 12:28:12 martin Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.webkit-gtk
PKG_SUPPORTED_OPTIONS=	debug debug-info enchant opengl webkit-jit
PKG_SUGGESTED_OPTIONS=	enchant opengl

.include "../../mk/bsd.prefs.mk"

# XXX JIT produces invalid code
# it's also entirely unsupported on powerpc and sparc
.if empty(MACHINE_PLATFORM:MNetBSD-*-i386) \
 && empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) \
 && empty(MACHINE_PLATFORM:MNetBSD-*-powerpc) \
 && empty(MACHINE_PLATFORM:MNetBSD-*-sparc64) \
 && empty(MACHINE_PLATFORM:MNetBSD-*-sparc) \
 && empty(MACHINE_PLATFORM:MSunOS-*)
PKG_SUGGESTED_OPTIONS+=	webkit-jit
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
CONFIGURE_ARGS+=	--enable-debug \
			--disable-optimizations
.else
CONFIGURE_ARGS+=	--disable-debug \
			--enable-optimizations
.endif
.if !empty(PKG_OPTIONS:Mdebug-info)
CONFIGURE_ARGS+=	--enable-debug-symbols=yes
.endif

#
# OpenGL support: enable support for GLX, WebGL and accelerated compositing
#
# TODO: should we split them in multiple options?
#
.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
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
