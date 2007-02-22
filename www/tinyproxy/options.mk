# $NetBSD: options.mk,v 1.2 2007/02/22 19:27:24 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tinyproxy
PKG_SUPPORTED_OPTIONS+=	socks5

PKG_SUGGESTED_OPTIONS+=	socks5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msocks5)
CONFIGURE_ARGS+=	--enable-socks
BUILDLINK_TRANSFORM+=	l:socks:socks5
.include "../../net/socks5/buildlink3.mk"
.endif
