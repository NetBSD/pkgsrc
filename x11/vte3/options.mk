# $NetBSD: options.mk,v 1.1 2020/11/07 10:05:11 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vte3
PKG_SUPPORTED_OPTIONS=	icu

.include "../../mk/bsd.options.mk"

#
# Enable legacy charsets support.
#
.if !empty(PKG_OPTIONS:Micu)
.  include "../../textproc/icu/buildlink3.mk"
MESON_ARGS+=	-Dicu=true
.else
MESON_ARGS+=	-Dicu=false
.endif
