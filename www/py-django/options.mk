# $NetBSD: options.mk,v 1.5 2008/04/12 22:43:13 jlam Exp $

PKG_OPTIONS_VAR =	PKG_OPTIONS.django
PKG_SUPPORTED_OPTIONS=	mysql psycopg1 psycopg2 sqlite
PKG_SUGGESTED_OPTIONS=	psycopg1

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PYPKGPREFIX}-mysqldb-[0-9]*:../../databases/py-mysqldb
PLIST.mysql=	yes
.endif

.if !empty(PKG_OPTIONS:Mpsycopg1)
DEPENDS+=	${PYPKGPREFIX}-psycopg-[0-9]*:../../databases/py-psycopg
.endif

.if !empty(PKG_OPTIONS:Mpsycopg2)
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
PLIST.psycopg2=	yes
.endif

.if !empty(PKG_OPTIONS:Mpsycopg1) || !empty(PKG_OPTIONS:Mpsycopg2)
PLIST.psycopg1=	yes
.endif

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2
PLIST.sqlite=	yes
.endif
