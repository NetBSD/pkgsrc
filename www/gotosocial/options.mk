# $NetBSD: options.mk,v 1.1 2024/06/18 09:25:24 nikita Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gotosocial
PKG_SUPPORTED_OPTIONS=	wasmsqlite3
PKG_SUGGESTED_OPTIONS=	wasmsqlite3

#PLIST_VARS+=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwasmsqlite3)
MAKE_ENV+=		GO_BUILDTAGS="wasmsqlite3"
.endif
