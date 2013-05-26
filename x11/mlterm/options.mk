# $NetBSD: options.mk,v 1.7 2013/05/26 18:18:25 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mlterm
PKG_SUPPORTED_OPTIONS=	ibus libind m17nlib mlterm-fb uim xft2
PKG_SUGGESTED_OPTIONS=
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	mlterm-fb
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		fb ibus ind m17nlib uim xft2

.if !empty(PKG_OPTIONS:Mmlterm-fb)
CONFIGURE_ARGS+=	--with-gui=xlib,fb
PLIST.fb=		yes
SPECIAL_PERMS+=		${PREFIX:Q}/bin/mlterm-fb ${SETUID_ROOT_PERMS}
CONF_FILES+=		${EGDIR}/font-fb ${PKG_SYSCONFDIR}/font-fb
.endif

.if !empty(PKG_OPTIONS:Mibus)
.include "../../inputmethod/ibus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ibus
PLIST.ibus=		yes
.endif

.if !empty(PKG_OPTIONS:Mlibind)
CONFIGURE_ARGS+=	--enable-ind
PLIST.ind=		yes
LICENSE+=		AND gnu-lgpl-v2
.endif

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
