# $NetBSD: options.mk,v 1.2 2024/10/21 11:18:34 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gotosocial
PKG_SUPPORTED_OPTIONS=	wasmsqlite3
PKG_SUGGESTED_OPTIONS=	wasmsqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwasmsqlite3)
MAKE_ENV+=		GO_BUILDTAGS="wasmsqlite3"
.endif
