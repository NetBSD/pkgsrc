# $NetBSD: options.mk,v 1.1 2006/02/22 23:00:37 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wwwoffle
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+= --with-ipv6
.endif
