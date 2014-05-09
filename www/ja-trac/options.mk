# $NetBSD: options.mk,v 1.6 2014/05/09 07:37:24 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.trac
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		sqlite pgsql mysql
PKG_SUGGESTED_OPTIONS=		sqlite
PKG_OPTIONS_LEGACY_OPTS=	psycopg2:pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
# py-sqlite2 is the external (vs. bundled with Python source)
# implementation of Python DB API 2.0 for sqlite version 3.  It is
# preferred over "py-sqlite3", the bundled version of sqlite3 support,
# because it is more up to date.
DEPENDS+=	${PYPKGPREFIX}-sqlite2>=2.5.5:../../databases/py-sqlite2
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 34 # py-sqlite2
.endif
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2:../../databases/py-psycopg2
.endif
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PYPKGPREFIX}-mysqldb>=1.2.2:../../databases/py-mysqldb
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 34 # py-mysqldb
.endif
