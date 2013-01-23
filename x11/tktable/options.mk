# $NetBSD: options.mk,v 1.1 2013/01/23 21:58:25 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tktable
PKG_SUPPORTED_OPTIONS=	threads
PKG_SUGGESTED_OPTIONS+=	threads

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mthreads)
.include "../../mk/pthread.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
