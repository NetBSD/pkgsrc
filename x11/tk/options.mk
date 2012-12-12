# $NetBSD: options.mk,v 1.2 2012/12/12 15:30:52 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tk
PKG_SUPPORTED_OPTIONS=	threads debug xft2
PKG_SUGGESTED_OPTIONS=	threads xft2

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-symbols
.endif

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threads
. include "../../mk/pthread.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=	--enable-xft
USE_TOOLS+=		pkg-config
. include "../../x11/libXft/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xft
.endif
