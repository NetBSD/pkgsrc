# $NetBSD: options.mk,v 1.2 2020/03/22 07:31:42 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qt5-qtmultimedia
PKG_SUPPORTED_OPTIONS=		alsa gstreamer openal pulseaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		gstreamer openal pulseaudio
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	alsa
.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=	yes
MAKE_ENV+=	QT_CONFIG+=alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
MAKE_ENV+=	QT_CONFIG+=-alsa
.endif

PLIST_VARS+=	gst
.if !empty(PKG_OPTIONS:Mgstreamer)
PLIST.gst=	yes
MAKE_ENV+=	QT_CONFIG+=gstreamer-1.0
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.else
MAKE_ENV+=	QT_CONFIG+=-gstreamer-1.0
.endif

.if !empty(PKG_OPTIONS:Mopenal)
MAKE_ENV+=	QT_CONFIG+=openal
.include "../../audio/openal-soft/buildlink3.mk"
.else
MAKE_ENV+=	QT_CONFIG+=-openal
.endif

PLIST_VARS+=	pulse
.if !empty(PKG_OPTIONS:Mpulseaudio)
PLIST.pulse=	yes
MAKE_ENV+=	LFLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib/pulseaudio
MAKE_ENV+=	QT_CONFIG+=pulseaudio
.include "../../audio/pulseaudio/buildlink3.mk"
.else
MAKE_ENV+=	QT_CONFIG+=-pulseaudio
.endif
