# $NetBSD: options.mk,v 1.48 2025/04/14 15:33:03 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.seamonkey

PKG_SUPPORTED_OPTIONS+=	alsa pulseaudio dbus

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	alsa pulseaudio dbus
.else
PKG_SUGGESTED_OPTIONS+=	dbus
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
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
