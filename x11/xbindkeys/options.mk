# $NetBSD: options.mk,v 1.2 2016/09/15 15:58:49 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xbindkeys
PKG_SUPPORTED_OPTIONS=	guile
PKG_SUGGESTED_OPTIONS+=	guile

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mguile)
CONFIGURE_ARGS+=	--enable-guile
USE_TOOLS+=		pkg-config
.include "../../lang/guile20/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-guile
.endif
