# $NetBSD: options.mk,v 1.4 2024/08/26 23:06:49 gutteridge Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.enlightenment16

PKG_OPTIONS_OPTIONAL_GROUPS=	sound
PKG_OPTIONS_GROUP.sound=	pulseaudio alsa

PKG_SUPPORTED_OPTIONS=		dbus pango vera-ttf
PKG_SUGGESTED_OPTIONS=		dbus pango pulseaudio vera-ttf

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	dbus

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
.include "../../sysutils/dbus/buildlink3.mk"
PLIST.dbus=		yes
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mpango)
CONFIGURE_ARGS+=	--enable-pango
.include "../../devel/pango/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pango
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-sound=pulseaudio
CONFIGURE_ARGS+=	--with-sndldr=sndfile
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-sound=alsa
CONFIGURE_ARGS+=	--with-sndldr=sndfile
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-sound=no
CONFIGURE_ARGS+=	--with-sndldr=none
.endif

# The upstream package includes its own Vera fonts. Because these
# have a different license, and are also included in some base OS
# distributions (like NetBSD's native X11), this has been made
# optional.
.if !empty(PKG_OPTIONS:Mvera-ttf)
DEPENDS+=	vera-ttf>=1.10:../../fonts/vera-ttf
.endif
