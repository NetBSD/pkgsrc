# $NetBSD: options.mk,v 1.2 2020/01/25 17:12:17 fox Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cliqz

PKG_SUPPORTED_OPTIONS=	alsa pulseaudio dbus wayland

PKG_SUGGESTED_OPTIONS+=	pulseaudio dbus

.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+= wayland
.endif

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

PLIST_VARS+=		wayland
.if !empty(PKG_OPTIONS:Mwayland)
# \todo Instead of using an option, determine if gtk3 was built with wayland.
PLIST.wayland=		yes
.endif
