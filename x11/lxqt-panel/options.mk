# $NetBSD: options.mk,v 1.2 2023/10/18 23:03:49 bacon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.lxqt-panel
PKG_SUPPORTED_OPTIONS=		alsa pulseaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa
PKG_SUGGESTED_OPTIONS.NetBSD=	pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_ARGS+=	-DVOLUME_USE_ALSA=ON
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DVOLUME_USE_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_ARGS+=	-DVOLUME_USE_PULSEAUDIO=ON
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DVOLUME_USE_PULSEAUDIO=OFF
.endif
