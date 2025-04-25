# $NetBSD: options.mk,v 1.1 2025/04/25 21:25:03 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.basilisk
PKG_SUPPORTED_OPTIONS=		dbus pulseaudio webrtc
#PKG_SUGGESTED_OPTIONS.NetBSD=	webrtc
#PKG_SUGGESTED_OPTIONS.Linux=	webrtc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-pulseaudio
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

.if !empty(PKG_OPTIONS:Mwebrtc)
CONFIGURE_ARGS+=	--enable-webrtc
.  include "../../graphics/libv4l/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-webrtc
.endif
