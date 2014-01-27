# $NetBSD: options.mk,v 1.1 2014/01/27 21:40:38 wiedi Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.goaccess
PKG_SUPPORTED_OPTIONS=	geoip wide-curses
PKG_SUGGESTED_OPTIONS=	wide-curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeoip)
.	include "../../net/GeoIP/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-geoip
.endif # option geoip

.if !empty(PKG_OPTIONS:Mwide-curses)
.	include "../../devel/ncursesw/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-utf8
.else
.	include "../../devel/ncurses/buildlink3.mk"
.endif # option wide-curses
