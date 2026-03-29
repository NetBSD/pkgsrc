# $NetBSD: options.mk,v 1.1 2026/03/29 16:54:28 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt6-qtwebengine
PKG_SUPPORTED_OPTIONS=	pulseaudio
PKG_SUGGESTED_OPTIONS=	pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_system_pulseaudio=ON
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_system_pulseaudio=OFF
.endif
