# $NetBSD: options.mk,v 1.61 2020/11/11 10:11:21 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.firefox

PKG_SUPPORTED_OPTIONS=	official-mozilla-branding
PKG_SUPPORTED_OPTIONS+=	debug debug-info mozilla-jemalloc webrtc
PKG_SUPPORTED_OPTIONS+=	alsa pulseaudio dbus
PLIST_VARS+=		debug

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	pulseaudio mozilla-jemalloc dbus webrtc
.else
PKG_SUGGESTED_OPTIONS+=	dbus
.endif

.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M[0-8].*)
PKG_SUGGESTED_OPTIONS+=	webrtc
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mmozilla-jemalloc)
CONFIGURE_ARGS+=	--enable-jemalloc
CONFIGURE_ARGS+=	--enable-replace-malloc
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug="-g -O0"
CONFIGURE_ARGS+=	--disable-optimize
CONFIGURE_ARGS+=	--enable-debug-js-modules
CONFIGURE_ARGS+=	--disable-install-strip
PLIST.debug=		yes
.else
.  if !empty(PKG_OPTIONS:Mdebug-info)
CONFIGURE_ARGS+=	--enable-debug-symbols
CONFIGURE_ARGS+=	--enable-optimize=-Og
CONFIGURE_ARGS+=	--disable-install-strip
.  else
CONFIGURE_ARGS+=	--disable-debug-symbols
CONFIGURE_ARGS+=	--enable-optimize=-O2
CONFIGURE_ARGS+=	--enable-install-strip
.  endif
CONFIGURE_ARGS+=	--disable-debug
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus-glib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
CONFIGURE_ARGS+=	--enable-official-branding
LICENSE=		mozilla-trademark-license
RESTRICTED=		Trademark holder prohibits distribution of modified versions.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
.endif

PLIST_VARS+=		webrtc
.if !empty(PKG_OPTIONS:Mwebrtc)
.include "../../graphics/libv4l/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-webrtc
PLIST.webrtc=		yes
.else
CONFIGURE_ARGS+=	--disable-webrtc
.endif
