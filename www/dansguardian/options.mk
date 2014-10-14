# $NetBSD: options.mk,v 1.1 2014/10/14 14:41:17 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dansguardian
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--with-dgdebug
.endif
