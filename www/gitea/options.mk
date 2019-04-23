# $NetBSD: options.mk,v 1.2 2019/04/23 06:04:41 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gitea
PKG_SUPPORTED_OPTIONS=	sqlite
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
GO_TAGS+=	sqlite sqlite_unlock_notify
.include "../../databases/sqlite3/buildlink3.mk"
.endif
