# $NetBSD: options.mk,v 1.1 2013/11/14 21:27:01 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.django
PKG_SUPPORTED_OPTIONS=	mysql oracle pgsql sqlite
PKG_SUGGESTED_OPTIONS=	pgsql

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PYPKGPREFIX}-mysqldb-[0-9]*:../../databases/py-mysqldb
PLIST.mysql=	yes
.endif

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
PLIST.sqlite=	yes
.endif
