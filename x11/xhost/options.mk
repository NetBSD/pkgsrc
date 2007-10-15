# $NetBSD: options.mk,v 1.1 2007/10/15 14:39:47 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xhost
PKG_SUPPORTED_OPTIONS+=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
