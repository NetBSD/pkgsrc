# $NetBSD: options.mk,v 1.4 2020/03/22 22:46:27 roy Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.goaccess
PKG_SUPPORTED_OPTIONS=	geoip wide-curses
PKG_SUGGESTED_OPTIONS=	wide-curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeoip)
.  include "../../net/GeoIP/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-geoip=legacy
.endif # geoip

.if !empty(PKG_OPTIONS:Mwide-curses)
CONFIGURE_ARGS+=	--enable-utf8
.endif
