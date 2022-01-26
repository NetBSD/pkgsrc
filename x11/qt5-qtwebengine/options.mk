# $NetBSD: options.mk,v 1.1 2022/01/26 18:24:08 mrg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt5-qtwebengine
PKG_SUPPORTED_OPTIONS=	pulseaudio
PKG_SUGGESTED_OPTIONS=	pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.endif
