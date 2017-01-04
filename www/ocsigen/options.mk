# $NetBSD: options.mk,v 1.5 2017/01/04 13:06:18 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocsigen
PKG_SUPPORTED_OPTIONS=	camlzip pgsql
PKG_OPTIONS_NONEMPTY_SETS=	database
PKG_OPTIONS_SET.database=	sqlite gdbm
PKG_SUGGESTED_OPTIONS=	gdbm camlzip

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	sqlite
.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=		ocaml-sqlite3>=0.23.0:../../databases/ocaml-sqlite3
CONFIGURE_ARGS+=	--with-sqlite
PLIST.sqlite=		yes
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

PLIST_VARS+=	dbm
.if !empty(PKG_OPTIONS:Mgdbm)
.include "../../databases/ocaml-dbm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dbm
PLIST.dbm=		yes
.else
CONFIGURE_ARGS+=	--without-dbm
.endif

PLIST_VARS+=	camlzip
.if !empty(PKG_OPTIONS:Mcamlzip)
DEPENDS+=		ocaml-zip-[0-9]*:../../archivers/ocaml-zip
CONFIGURE_ARGS+=	--with-camlzip
PLIST.camlzip=		yes
.else
CONFIGURE_ARGS+=	--without-camlzip
.endif

PLIST_VARS+=	pgsql
.if !empty(PKG_OPTIONS:Mpgsql)
.include	"../../databases/pgocaml/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql
PLIST.pgsql=		yes
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif
