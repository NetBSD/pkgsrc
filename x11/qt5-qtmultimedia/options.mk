# $NetBSD: options.mk,v 1.10 2023/12/30 16:18:33 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qt5-qtmultimedia
PKG_SUPPORTED_OPTIONS=		alsa gstreamer openal pulseaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		gstreamer openal
PKG_SUGGESTED_OPTIONS+=		pulseaudio
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	alsa
.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=	yes
QMAKE_ARGS+=	-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
QMAKE_ARGS+=	-no-alsa
.endif

PLIST_VARS+=	gst
.if !empty(PKG_OPTIONS:Mgstreamer)
PLIST.gst=	yes
QMAKE_ARGS+=	-gstreamer 1.0
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.else
QMAKE_ARGS+=	-no-gstreamer
.endif

PLIST_VARS+=	openal
.if !empty(PKG_OPTIONS:Mopenal)
PLIST.openal=	yes
QMAKE_ARGS+=	-openal
.include "../../audio/openal-soft/buildlink3.mk"
.else
QMAKE_ARGS+=	-no-openal
.endif

PLIST_VARS+=	pulse
.if !empty(PKG_OPTIONS:Mpulseaudio)
PLIST.pulse=	yes
MAKE_ENV+=	LFLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib/pulseaudio
QMAKE_ARGS+=	-pulseaudio
.include "../../audio/pulseaudio/buildlink3.mk"
.else
QMAKE_ARGS+=	-no-pulseaudio
.endif

PLIST_VARS+=		audioengine
.if ${OPSYS} == "QNX" || ${OPSYS} == "Darwin" || empty(PKG_OPTIONS:Mgstreamer)
PLIST.audioengine=	yes
.endif
