# $NetBSD: options.mk,v 1.1.2.1 2019/04/28 16:41:30 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gitea
PKG_SUPPORTED_OPTIONS=	sqlite
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
GO_TAGS+=	sqlite sqlite_unlock_notify
.include "../../databases/sqlite3/buildlink3.mk"
.endif
