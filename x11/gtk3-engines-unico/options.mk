# $NetBSD: options.mk,v 1.1 2014/04/28 01:59:52 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk3-engines-unico
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
