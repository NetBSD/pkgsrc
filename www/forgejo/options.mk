# $NetBSD: options.mk,v 1.1 2026/10/18 08:23:57 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.forgejo
PKG_SUPPORTED_OPTIONS=	sqlite
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
GO_TAGS+=	sqlite sqlite_unlock_notify
.include "../../databases/sqlite3/buildlink3.mk"
.endif
