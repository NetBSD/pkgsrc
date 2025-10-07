# $NetBSD: options.mk,v 1.2 2025/10/07 21:04:12 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.tk90
PKG_SUPPORTED_OPTIONS=		aqua debug xft2
#PKG_SUGGESTED_OPTIONS+=

.include "../../mk/bsd.prefs.mk"

# xxx NetBSD 64bit detected but not supported in configure script:
# configure: WARNING: 64bit support being disabled -- don't know magic for this platform
.if ${MACHINE_ARCH} == "sparc64"
CONFIGURE_ARGS+=	--enable-64bit-vis
.else
.  for plat in ${LP64PLATFORMS}
.    if ${MACHINE_PLATFORM:M${plat}}
CONFIGURE_ARGS+=	--enable-64bit
.    endif
.  endfor
.endif

PLIST_VARS+=		aqua
.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=	xft2
.else
PKG_SUGGESTED_OPTIONS+=	aqua
.endif

.include "../../mk/bsd.options.mk"

# IMPORTANT: This option should be enabled on a system without X11.
# Otherwise some X11 headers are installed and will break X11 compatibility.
.if !empty(PKG_OPTIONS:Maqua)
CONFIGURE_ARGS+=	--enable-aqua
CONFIGURE_ARGS+=	--without-x
PLIST.aqua=		yes
.else
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib${LIBABISUFFIX}
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-symbols
.endif

.if !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=	--enable-xft
USE_TOOLS+=		pkg-config
.include "../../x11/libXft/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xft
.endif
