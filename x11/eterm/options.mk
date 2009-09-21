# $NetBSD: options.mk,v 1.3 2009/09/21 07:29:30 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.eterm
PKG_SUPPORTED_OPTIONS=	xim
PKG_SUGGESTED_OPTIONS=	xim

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
PKG_SUPPORTED_OPTIONS+=	mmx
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--enable-mmx
.endif

.if !empty(PKG_OPTIONS:Mxim)
CONFIGURE_ARGS+=	--enable-xim
.endif
