# $NetBSD: options.mk,v 1.69 2022/07/24 16:33:09 rjs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.firefox

PKG_SUPPORTED_OPTIONS=	official-mozilla-branding
PKG_SUPPORTED_OPTIONS+=	debug debug-info mozilla-jemalloc webrtc
PKG_SUPPORTED_OPTIONS+=	dbus
PKG_SUPPORTED_OPTIONS+=	alsa pulseaudio sunaudio jack

PKG_SUGGESTED_OPTIONS+=	dbus

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	pulseaudio mozilla-jemalloc webrtc
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	sunaudio
.endif

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} >= 090000
PKG_SUGGESTED_OPTIONS+=	webrtc
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
AUDIO_BACKENDS+=	alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmozilla-jemalloc)
CONFIGURE_ARGS+=	--enable-jemalloc
CONFIGURE_ARGS+=	--enable-replace-malloc
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug="-g -Og"
CONFIGURE_ARGS+=	--disable-optimize
CONFIGURE_ARGS+=	--enable-debug-js-modules
CONFIGURE_ARGS+=	--disable-install-strip
.else
.  if !empty(PKG_OPTIONS:Mdebug-info)
CONFIGURE_ARGS+=	--enable-debug-symbols
CONFIGURE_ARGS+=	--enable-optimize=-O2
CONFIGURE_ARGS+=	--disable-install-strip
.  else
CONFIGURE_ARGS+=	--disable-debug-symbols
CONFIGURE_ARGS+=	--enable-optimize=-O2
CONFIGURE_ARGS+=	--enable-install-strip
.  endif
CONFIGURE_ARGS+=	--disable-debug
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
AUDIO_BACKENDS+=	pulseaudio
.include "../../audio/pulseaudio/buildlink3.mk"
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
.else
CONFIGURE_ARGS+=	--with-branding=browser/branding/unofficial
.endif

.if !empty(PKG_OPTIONS:Msunaudio)
AUDIO_BACKENDS+=	sunaudio
.endif

.if !empty(PKG_OPTIONS:Mjack)
AUDIO_BACKENDS+=	jack
.include "../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwebrtc)
.include "../../graphics/libv4l/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-webrtc
.else
CONFIGURE_ARGS+=	--disable-webrtc
.endif

CONFIGURE_ARGS+=	--audio-backends=${AUDIO_BACKENDS:ts,}
