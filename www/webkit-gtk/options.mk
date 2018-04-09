# $NetBSD: options.mk,v 1.12 2018/04/09 08:33:48 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.webkit-gtk
PKG_SUPPORTED_OPTIONS=	debug enchant introspection opengl webkit-jit
PKG_SUGGESTED_OPTIONS=	enchant introspection opengl

PLIST_VARS=	introspection

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
CMAKE_ARGS+=	-DENABLE_JIT=ON
.else
CMAKE_ARGS+=	-DENABLE_JIT=OFF
.endif

#
# OpenGL support: enable support for GLX, WebGL and accelerated compositing
#
.if !empty(PKG_OPTIONS:Mopengl)
CMAKE_ARGS+=	-DENABLE_WEBGL=ON
.else
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

#
# Debug build
#
.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
.else
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
.endif

#
# Introspection
#
.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=				yes
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.5
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_INTROSPECTION=ON
.else
CMAKE_ARGS+=	-DENABLE_INTROSPECTION=OFF
.endif
