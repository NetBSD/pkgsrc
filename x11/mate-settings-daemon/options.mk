# $NetBSD: options.mk,v 1.1 2016/05/21 19:15:32 youri Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mate-settings-daemon
PKG_SUPPORTED_OPTIONS=		nss polkit
PKG_OPTIONS_OPTIONAL_GROUPS+=	audio
PKG_OPTIONS_GROUP.audio=	pulseaudio gstreamer
PKG_SUGGESTED_OPTIONS=		nss polkit gstreamer

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	nss polkit

.if !empty(PKG_OPTIONS:Mnss)
.include "../../devel/nss/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-smartcard-support
PLIST.nss=	yes
.else
CONFIGURE_ARGS+=	--disable-smartcard-support
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pulse
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gstreamer
.else
CONFIGURE_ARGS+=	--disable-gstreamer
.endif

.if !empty(PKG_OPTIONS:Mpolkit)
.include "../../security/polkit/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-polkit
PLIST.polkit=	yes
MAKE_DIRS+=	${PKG_SYSCONFDIR}/dbus-1/system.d
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/dbus-1/system.d/org.mate.SettingsDaemon.DateTimeMechanism.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.mate.SettingsDaemon.DateTimeMechanism.conf
.else
CONFIGURE_ARGS+=	--disable-polkit
.endif
