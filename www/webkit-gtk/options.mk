# $NetBSD: options.mk,v 1.14.4.1 2019/05/05 14:26:11 bsiegert Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.webkit-gtk
PKG_SUPPORTED_OPTIONS=	debug enchant introspection opengl webkit-jit
PKG_SUGGESTED_OPTIONS=	enchant introspection opengl

PLIST_VARS=	introspection

.include "../../mk/bsd.prefs.mk"

#
# Platforms that support the webkit-jit option
#
# Please see:
#  Source/cmake/WebKitFeatures.cmake
#  Source/WTF/wtf/Platform.h
#
WEBKIT_JIT_MACHINE_PLATFORMS+=	Darwin-*-*
WEBKIT_JIT_MACHINE_PLATFORMS+=	DragonFly-*-*
WEBKIT_JIT_MACHINE_PLATFORMS+=	FreeBSD-*-x86_64 FreeBSD-*-aarch64
WEBKIT_JIT_MACHINE_PLATFORMS+=	Linux-*-x86_64 Linux-*-arm*
WEBKIT_JIT_MACHINE_PLATFORMS+=	Linux-*-aarch64 Linux-*-mips*
WEBKIT_JIT_MACHINE_PLATFORMS+=	NetBSD-*-x86_64 NetBSD-*-aarch64

.if !empty(WEBKIT_JIT_MACHINE_PLATFORMS:@.PLAT.@${MACHINE_PLATFORM:M${.PLAT.}}@)
PKG_SUGGESTED_OPTIONS+=	webkit-jit
.endif

.include "../../mk/bsd.options.mk"

#
# JIT support
#
.if !empty(PKG_OPTIONS:Mwebkit-jit)
CMAKE_ARGS+=	-DENABLE_JIT=ON
CMAKE_ARGS+=	-DENABLE_C_LOOP=OFF
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
.include "../../textproc/enchant2/buildlink3.mk"
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
