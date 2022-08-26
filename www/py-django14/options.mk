# $NetBSD: options.mk,v 1.12 2022/08/26 18:39:43 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.django
PKG_SUPPORTED_OPTIONS=	oracle pgsql sqlite # mysql
PKG_SUGGESTED_OPTIONS=	pgsql

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}

#.if !empty(PKG_OPTIONS:Mmysql)
#DEPENDS+=	${PYPKGPREFIX}-mysqldb-[0-9]*:../../databases/py-mysqldb
#PYTHON_VERSIONS_ACCEPTED= 27 # py-mysqldb
#PLIST.mysql=	yes
#.endif

.if !empty(PKG_OPTIONS:Moracle)
DEPENDS+=	${PYPKGPREFIX}-cx_Oracle-[0-9]*:../../databases/py-cx_Oracle
PLIST.oracle=	yes
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
PLIST.pgsql=	yes
.endif

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2
PYTHON_VERSIONS_ACCEPTED= 27 # py-sqlite2
PLIST.sqlite=	yes
.endif
