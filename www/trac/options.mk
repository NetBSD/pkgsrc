# $NetBSD: options.mk,v 1.2 2016/09/11 15:48:27 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.trac
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	sqlite psycopg2
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3
.endif
# trac 0.12 dropped support for py-PgSQL.  Switching to py-psycopg2 with
# an existing database that used to be accessed by py-PgSQL worked.
.if !empty(PKG_OPTIONS:Mpsycopg2)
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2:../../databases/py-psycopg2
.endif
# Upstream has MySQL support but it is not really recommended:
# https://trac.edgewall.org/wiki/MySqlDb
