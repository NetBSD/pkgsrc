# $NetBSD: options.mk,v 1.3 2025/12/20 19:45:27 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.basilisk
PKG_SUPPORTED_OPTIONS=		dbus pulseaudio

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
