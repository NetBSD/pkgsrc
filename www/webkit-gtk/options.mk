# $NetBSD: options.mk,v 1.9 2015/07/12 00:44:46 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.webkit-gtk
PKG_SUPPORTED_OPTIONS=	enchant opengl webkit-jit
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
PKG_SUGGESTED_OPTIONS+= webkit-jit
.endif

.include "../../mk/bsd.options.mk"

#
# JIT support
#
.if !empty(PKG_OPTIONS:Mwebkit-jit)
CMAKE_ARGS+=	-DENABLE_JIT=ON
CMAKE_ARGS+=	-DENABLE_LLINT_C_LOOP=ON
.else
CMAKE_ARGS+=	-DENABLE_JIT=OFF
CMAKE_ARGS+=	-DENABLE_LLINT_C_LOOP=OFF
.endif

#
# OpenGL support: enable support for GLX, WebGL and accelerated compositing
#
# TODO: should we split them in multiple options?
#
.if !empty(PKG_OPTIONS:Mopengl)
CMAKE_ARGS+=	-DENABLE_3D_RENDERING=ON
CMAKE_ARGS+=	-DENABLE_WEBGL=ON
.else
CMAKE_ARGS+=	-DENABLE_3D_RENDERING=OFF
CMAKE_ARGS+=	-DENABLE_WEBGL=OFF
.endif

#
# Spellcheck support using enchant
#
.if !empty(PKG_OPTIONS:Menchant)
CMAKE_ARGS+=	-DENABLE_SPELLCHECK=ON
.include "../../textproc/enchant/buildlink3.mk"
.else
CMAKE_ARGS+=	-DENABLE_SPELLCHECK=OFF
.endif
