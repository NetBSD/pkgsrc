# $NetBSD: options.mk,v 1.1 2019/02/01 15:21:29 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnurl
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
