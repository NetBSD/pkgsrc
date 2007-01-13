# $NetBSD: options.mk,v 1.2 2007/01/13 12:11:13 hira Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mlterm
PKG_SUPPORTED_OPTIONS=	uim xft2
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Muim)
.include "../../inputmethod/uim/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-uim
PLIST_SUBST+=		UIM=
.else
PLIST_SUBST+=		UIM="@comment "
.endif

.if !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=	--with-type-engines=xft
.endif
