# $NetBSD: options.mk,v 1.14 2023/02/14 18:09:43 nikita Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.django
PKG_SUPPORTED_OPTIONS=	oracle sqlite
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Moracle)
DEPENDS+=	${PYPKGPREFIX}-cx_Oracle-[0-9]*:../../databases/py-cx_Oracle
PLIST.oracle=	yes
.endif

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2
PYTHON_VERSIONS_ACCEPTED= 27 # py-sqlite2
PLIST.sqlite=	yes
.endif
