# $NetBSD: options.mk,v 1.1 2005/11/25 21:31:06 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk2+
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif
