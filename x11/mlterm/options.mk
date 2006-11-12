# $NetBSD: options.mk,v 1.1 2006/11/12 15:13:56 hira Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mlterm
PKG_SUPPORTED_OPTIONS=	uim
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Muim)
.include "../../inputmethod/uim/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-uim
PLIST_SUBST+=		UIM=
.else
PLIST_SUBST+=		UIM="@comment "
.endif
