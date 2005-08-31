# $NetBSD: options.mk,v 1.1 2005/08/31 15:23:09 hira Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-utils
PKG_SUPPORTED_OPTIONS=	dbh
PKG_SUGGESTED_OPTIONS=	dbh

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbh)
CONFIGURE_ARGS+=	--enable-dbh
.else
CONFIGURE_ARGS+=	--disable-dbh
.endif
