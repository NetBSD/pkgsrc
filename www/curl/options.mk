# $NetBSD: options.mk,v 1.1 2006/08/10 14:18:16 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.curl
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
