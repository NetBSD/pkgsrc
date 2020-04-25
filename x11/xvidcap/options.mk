# $NetBSD: options.mk,v 1.1 2020/04/25 14:04:26 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xvidcap
PKG_SUPPORTED_OPTIONS=	dbus lame theora
PKG_SUGGESTED_OPTIONS=	lame theora

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlame)
CONFIGURE_ARGS+=	--enable-libmp3lame
.include "../../audio/lame/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtheora)
CONFIGURE_ARGS+=	--enable-libtheora
.include "../../multimedia/libtheora/buildlink3.mk"
.endif
