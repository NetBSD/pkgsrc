# $NetBSD: options.mk,v 1.1 2022/02/05 20:51:07 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.arcticfox
PKG_SUPPORTED_OPTIONS=		dbus pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
.include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-pulseaudio
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif
