# $NetBSD: options.mk,v 1.21 2020/03/10 18:14:04 leot Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.webkit-gtk
PKG_SUPPORTED_OPTIONS=	debug enchant introspection opengl webkit-jit wayland
PKG_SUGGESTED_OPTIONS=	enchant introspection opengl
.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=	wayland
.endif

PLIST_VARS=	introspection

.include "../../mk/bsd.fast.prefs.mk"

#
# Platforms that support the webkit-jit option
#
# Please see:
#  Source/cmake/WebKitFeatures.cmake
#  Source/WTF/wtf/PlatformEnable.h
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
CMAKE_ARGS+=	-DENABLE_OPENGL=ON
.else
CMAKE_ARGS+=	-DENABLE_OPENGL=OFF
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

#
# Wayland display server support
#
.if !empty(PKG_OPTIONS:Mwayland)
CMAKE_ARGS+=	-DENABLE_WAYLAND_TARGET=ON
CMAKE_ARGS+=	-DUSE_WPE_RENDERER=OFF # TODO
.include "../../devel/wayland/buildlink3.mk"
.else
CMAKE_ARGS+=	-DENABLE_WAYLAND_TARGET=OFF
.endif
