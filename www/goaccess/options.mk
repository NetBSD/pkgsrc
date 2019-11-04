# $NetBSD: options.mk,v 1.3 2019/11/04 22:09:55 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.goaccess
PKG_SUPPORTED_OPTIONS=	geoip wide-curses
PKG_SUGGESTED_OPTIONS=	wide-curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeoip)
.  include "../../net/GeoIP/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-geoip=legacy
.endif # geoip

.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../devel/ncursesw/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-utf8
.else
.  include "../../devel/ncurses/buildlink3.mk"
.endif # wide-curses
