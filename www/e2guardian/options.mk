# $NetBSD: options.mk,v 1.1 2017/03/03 14:09:18 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.e2guardian
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--with-dgdebug
.endif
