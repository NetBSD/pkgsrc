# $NetBSD: options.mk,v 1.1 2016/05/21 19:16:49 youri Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-terminal
PKG_SUPPORTED_OPTIONS=	skey
PKG_SUGGESTED_OPTIONS=	skey

PLIST_VARS+=	skey

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mskey)
CONFIGURE_ARGS+=	--enable-skey
PLIST.skey=		yes
.else
CONFIGURE_ARGS+=	--disable-skey
.endif
