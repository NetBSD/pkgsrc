# $NetBSD: options.mk,v 1.1 2026/08/30 14:25:05 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.webkit-gtk
PKG_SUPPORTED_OPTIONS=	debug wayland webkit-jit webkit-developer-mode webkit-webdriver
PKG_SUGGESTED_OPTIONS=

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=	wayland
.endif

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
# breaks compilation, with
#In file included from /tmp/www/webkit-gtk60/work/webkitgtk-2.52.6/Source/JavaScriptCore/jit/JIT.h:41,
#                 from /tmp/www/webkit-gtk60/work/webkitgtk-2.52.6/Source/JavaScriptCore/bytecode/Repatch.cpp:50,
#                 from /tmp/www/webkit-gtk60/work/webkitgtk-2.52.6/cmake-pkgsrc-build/JavaScriptCore/DerivedSources/unified-sources/UnifiedSource-f0a787a9-11.cpp:3:
#/tmp/www/webkit-gtk60/work/webkitgtk-2.52.6/Source/JavaScriptCore/jit/PCToCodeOriginMap.h:52:45: error: 'OpcodeOrigin' has not been declared
#   52 |     WasmOrigin(CallSiteIndex callSiteIndex, OpcodeOrigin opcodeOrigin)
#      |                                             ^~~~~~~~~~~~
#/tmp/www/webkit-gtk60/work/webkitgtk-2.52.6/Source/JavaScriptCore/jit/PCToCodeOriginMap.h:58:5: error: 'OpcodeOrigin' does not name a type; did you mean 'CodeOrigin'?
#   58 |     OpcodeOrigin m_opcodeOrigin { };
#      |     ^~~~~~~~~~~~
#      |     CodeOrigin
#/tmp/www/webkit-gtk60/work/webkitgtk-2.52.6/Source/JavaScriptCore/jit/PCToCodeOriginMap.h: In constructor 'JSC::Wasm::WasmOrigin::WasmOrigin(JSC::CallSiteIndex, int)':
#/tmp/www/webkit-gtk60/work/webkitgtk-2.52.6/Source/JavaScriptCore/jit/PCToCodeOriginMap.h:54:11: error: class 'JSC::Wasm::WasmOrigin' does not have any field named 'm_opcodeOrigin'
#   54 |         , m_opcodeOrigin(opcodeOrigin)
#      |           ^~~~~~~~~~~~~~
#
#PKG_SUGGESTED_OPTIONS+=	webkit-jit
.endif

.include "../../mk/bsd.options.mk"

#
# JIT support
#
.if !empty(PKG_OPTIONS:Mwebkit-jit)
CMAKE_CONFIGURE_ARGS+=	-DENABLE_JIT=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_C_LOOP=OFF
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_JIT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_C_LOOP=ON
.endif

#
# Debug build
#
.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
INSTALL_UNSTRIPPED=	yes
# This does not disable optimisations, merely avoids #error if there are none.
#CFLAGS+=		-DRELEASE_WITHOUT_OPTIMIZATIONS
.else
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
.endif

#
# Wayland display server support
#
.if !empty(PKG_OPTIONS:Mwayland)
CMAKE_CONFIGURE_ARGS+=	-DENABLE_WAYLAND_TARGET=ON
.include "../../devel/wayland/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_WAYLAND_TARGET=OFF
.endif

# DEVELOPER_MODE enables WEBKIT_EXEC_PATH env var so MiniBrowser can be run
# from the build tree without installing; also auto-discovers helpers next to
# the MiniBrowser binary itself.
.if !empty(PKG_OPTIONS:Mwebkit-developer-mode)
CMAKE_CONFIGURE_ARGS+=		-DDEVELOPER_MODE=ON
# DEVELOPER_MODE defaults ENABLE_API_TESTS and ENABLE_LAYOUT_TESTS to ON, but
# the release tarball does not ship those test sources; disable them explicitly.
# CLANGD_AUTO_SETUP is also enabled by DEVELOPER_MODE but requires Tools/clangd/
# scripts not present in the tarball.
CMAKE_CONFIGURE_ARGS+=		-DENABLE_API_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=		-DENABLE_LAYOUT_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=		-DCLANGD_AUTO_SETUP=OFF
CMAKE_CONFIGURE_ARGS+=		-DDEVELOPER_MODE_FATAL_WARNINGS=OFF
.endif

#
# Tool for interacting with the browser from Python. Mostly for testing.
#
.if !empty(PKG_OPTIONS:Mwebkit-webdriver)
CMAKE_CONFIGURE_ARGS+=	-DENABLE_WEBDRIVER=ON
PLIST_SRC+=		${.CURDIR}/../../www/webkit-gtk41/PLIST.webdriver
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_WEBDRIVER=OFF
.endif
