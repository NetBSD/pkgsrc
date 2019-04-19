# $NetBSD: options.mk,v 1.1 2019/04/19 14:02:03 fox Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cliqz

PKG_SUPPORTED_OPTIONS=	alsa pulseaudio dbus

PKG_SUGGESTED_OPTIONS+=	pulseaudio dbus

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
MOZ_CONFIGURE_ARGS+=	"ac_add_options --enable-alsa"
.include "../../audio/alsa-lib/buildlink3.mk"
.else
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-alsa"
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --enable-pulseaudio"
.else
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-pulseaudio"
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus-glib/buildlink3.mk"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --enable-dbus"
.else
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-dbus"
.endif
