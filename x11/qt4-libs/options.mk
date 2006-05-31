# $NetBSD: options.mk,v 1.2 2006/05/31 19:18:07 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt4
PKG_SUPPORTED_OPTIONS=	cups debug sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.  include "../../print/cups/buildlink3.mk"
CONFIGURE_ARGS+=	-cups
.else
CONFIGURE_ARGS+=	-no-cups
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CC+=			-ggdb
CXX+=			-ggdb
CONFIGURE_ARGS+=	--debug
INSTALL_UNSTRIPPED=	yes
.endif

.if !empty(PKG_OPTIONS:Msqlite)
.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	-qt-sql-sqlite
.else
CONFIGURE_ARGS+=	-no-sql-sqlite
.endif
