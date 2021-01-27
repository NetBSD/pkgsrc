# $NetBSD: options.mk,v 1.7 2021/01/27 08:17:31 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.goaccess
PKG_SUPPORTED_OPTIONS=	geoip ssl wide-curses
PKG_SUGGESTED_OPTIONS=	ssl wide-curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeoip)
.  include "../../geography/libmaxminddb/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-geoip=mmdb
.endif # geoip

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl
.endif # ssl

.if !empty(PKG_OPTIONS:Mwide-curses)
CONFIGURE_ARGS+=	--enable-utf8
.endif #wide-curses
