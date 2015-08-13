# $NetBSD: options.mk,v 1.3 2015/08/13 20:32:30 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tinyproxy
PKG_SUPPORTED_OPTIONS+=	socks5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msocks5)
CONFIGURE_ARGS+=	--enable-socks
BUILDLINK_TRANSFORM+=	l:socks:socks5
.include "../../net/socks5/buildlink3.mk"
.endif
