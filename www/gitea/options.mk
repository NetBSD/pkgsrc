# $NetBSD: options.mk,v 1.1 2019/03/24 21:34:23 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gitea
PKG_SUPPORTED_OPTIONS=	sqlite
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
GO_TAGS+=	sqlite
.endif
