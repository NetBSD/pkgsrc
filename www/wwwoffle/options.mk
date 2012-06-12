# $NetBSD: options.mk,v 1.2 2012/06/12 15:46:04 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wwwoffle
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+= --with-ipv6
.endif
