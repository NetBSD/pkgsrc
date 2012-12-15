# $NetBSD: options.mk,v 1.3 2012/12/15 11:16:07 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocsigen
PKG_SUPPORTED_OPTIONS=	sqlite camlzip
PKG_SUGGESTED_OPTIONS=	camlzip

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	sqlite
.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=		ocaml-sqlite3>=0.23.0:../../databases/ocaml-sqlite3
CONFIGURE_ARGS+=	--with-sqlite
PLIST.sqlite=		yes
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

PLIST_VARS+=	camlzip
.if !empty(PKG_OPTIONS:Mcamlzip)
DEPENDS+=		ocaml-zip-[0-9]*:../../archivers/ocaml-zip
CONFIGURE_ARGS+=	--with-camlzip
PLIST.camlzip=		yes
.else
CONFIGURE_ARGS+=	--without-camlzip
.endif
