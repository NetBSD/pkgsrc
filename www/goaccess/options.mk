# $NetBSD: options.mk,v 1.6 2020/03/24 11:50:10 roy Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.goaccess
PKG_SUPPORTED_OPTIONS=	geoip ssl tokyocabinet wide-curses
PKG_SUGGESTED_OPTIONS=	ssl tokyocabinet wide-curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeoip)
.  include "../../net/GeoIP/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-geoip=legacy
.endif # geoip

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl
.endif # ssl

.if !empty(PKG_OPTIONS:Mtokyocabinet)
CONFIGURE_ARGS+=	--enable-tcb=btree
.  include "../../databases/tokyocabinet/buildlink3.mk"
.endif #tokyocabinet

.if !empty(PKG_OPTIONS:Mwide-curses)
CONFIGURE_ARGS+=	--enable-utf8
.endif #wide-curses
