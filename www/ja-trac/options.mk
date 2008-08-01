# $NetBSD: options.mk,v 1.1 2008/08/01 08:46:55 obache Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.trac
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		sqlite pgsql psycopg2 mysql
PKG_SUGGESTED_OPTIONS=		sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite2>=2.3.2:../../databases/py-sqlite2
.endif
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PYPKGPREFIX}-PgSQL>=2.4:../../databases/py-PgSQL
.endif
.if !empty(PKG_OPTIONS:Mpsycopg2)
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2:../../databases/py-psycopg2
.endif
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PYPKGPREFIX}-mysqldb>=1.2.1:../../databases/py-mysqldb
.endif
