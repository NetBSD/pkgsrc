# $NetBSD: options.mk,v 1.2 2019/12/14 12:35:20 ng0 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnurl
PKG_SUPPORTED_OPTIONS=	inet6 tests
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mtests)
USE_TOOLS+=	perl
.endif
