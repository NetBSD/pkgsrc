# $NetBSD: options.mk,v 1.2 2011/03/15 06:04:03 obache Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.trac
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		sqlite pgsql mysql
PKG_SUGGESTED_OPTIONS=		sqlite
PKG_OPTIONS_LEGACY_OPTS=	psycopg2:pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite2>=2.3.2:../../databases/py-sqlite2
.endif
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2:../../databases/py-psycopg2
.endif
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PYPKGPREFIX}-mysqldb>=1.2.1:../../databases/py-mysqldb
.endif
