# $NetBSD: options.mk,v 1.1 2025/02/06 09:57:38 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.chromium
PKG_OPTIONS_REQUIRED_GROUPS=	audio
PKG_OPTIONS_GROUP.audio=	alsa pulseaudio sunaudio
PKG_SUPPORTED_OPTIONS+=		debug

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		sunaudio
.else
PKG_SUGGESTED_OPTIONS+=		pulseaudio
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msunaudio)
GN_ARGS+=	use_audioio=true
.else
GN_ARGS+=	use_audioio=false
.endif

.if !empty(PKG_OPTIONS:Malsa)
GN_ARGS+=	use_alsa=true
.include "../../audio/alsa-lib/buildlink3.mk"
.else
GN_ARGS+=	use_alsa=false
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
WITH_PA=	yes
GN_ARGS+=	use_pulseaudio=true
.include "../../audio/pulseaudio/buildlink3.mk"
.else
WITH_PA=	no
GN_ARGS+=	use_pulseaudio=false
.endif

.if !empty(PKG_OPTIONS:Mdebug)
BUILDTYPE=		Debug
GN_ARGS+=		is_debug=true
GN_ARGS+=		symbol_level=1
GN_BOOTSTRAP_FLAGS+=	--debug
GN_VERBOSE=		#-v
INSTALL_UNSTRIPPED=	yes
.else
BUILDTYPE=		Release
GN_ARGS+=		is_official_build=true
GN_ARGS+=		is_component_build=false
GN_ARGS+=		is_debug=false
GN_ARGS+=		blink_symbol_level=0
GN_ARGS+=		symbol_level=0
GN_VERBOSE=		# empty
.endif
