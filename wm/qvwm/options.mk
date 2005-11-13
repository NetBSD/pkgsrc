# $NetBSD: options.mk,v 1.1 2005/11/13 19:18:14 martin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qvwm
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif
