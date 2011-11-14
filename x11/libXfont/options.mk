# $NetBSD: options.mk,v 1.1 2011/11/14 14:07:35 cheusov Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libXfont
PKG_SUPPORTED_OPTIONS+=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
