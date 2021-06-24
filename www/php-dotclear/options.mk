# $NetBSD: options.mk,v 1.1 2021/06/24 02:32:27 triaxx Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.dotclear

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql sqlite

PKG_SUGGESTED_OPTIONS=		mysql

.include "../../mk/bsd.options.mk"

###
### Use mysql backend.
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli-[0-9]*:../../databases/php-mysqli
.endif

###
### Use pgsql backend.
###
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql-[0-9]*:../../databases/php-pgsql
.endif

###
### Use sqlite backend.
###
.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=		${PHP_PKG_PREFIX}-pdo_sqlite-[0-9]*:../../databases/php-pdo_sqlite
.endif
