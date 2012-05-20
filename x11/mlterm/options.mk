# $NetBSD: options.mk,v 1.5 2012/05/20 06:07:31 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mlterm
PKG_SUPPORTED_OPTIONS=	m17nlib uim xft2
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		m17nlib uim xft2

.if !empty(PKG_OPTIONS:Mm17nlib)
.include "../../devel/m17n-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-m17nlib
PLIST.m17nlib=		yes
.endif

.if !empty(PKG_OPTIONS:Muim)
.include "../../inputmethod/uim/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-uim
PLIST.uim=		yes
LICENSE+=		AND gnu-lgpl-v2
.endif

.if !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=	--with-type-engines=xft
PLIST.xft2=		yes
.endif
