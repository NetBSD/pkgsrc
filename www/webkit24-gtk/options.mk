# $NetBSD: options.mk,v 1.2 2016/12/01 14:27:21 martin Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.webkit-gtk
PKG_SUPPORTED_OPTIONS=	debug enchant opengl webkit-jit introspection
PKG_SUGGESTED_OPTIONS=	enchant opengl introspection

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
CONFIGURE_ARGS+=	--enable-debug \
			--disable-optimizations
.else
CONFIGURE_ARGS+=	--disable-debug \
			--enable-optimizations
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

#
# Introspection
#
.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection	= yes
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.5
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection
.else
CONFIGURE_ARGS+=	--disable-introspection
.endif
