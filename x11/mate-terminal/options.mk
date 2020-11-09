# $NetBSD: options.mk,v 1.2 2020/11/09 23:48:31 gutteridge Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-terminal
PKG_SUPPORTED_OPTIONS=	skey
PKG_SUGGESTED_OPTIONS=	skey

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mskey)
CONFIGURE_ARGS+=	--enable-skey
.else
CONFIGURE_ARGS+=	--disable-skey
.endif
