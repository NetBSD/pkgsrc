# $NetBSD: options.mk,v 1.2 2017/03/01 11:43:30 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-nextcloud

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql sqlite3 pgsql

PKG_SUGGESTED_OPTIONS=	sqlite3

.include "../../mk/bsd.options.mk"

###
### Use mysql, pgsql, or sqlite backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=5.2.0:../../databases/php-pdo_mysql
.elif !empty(PKG_OPTIONS:Msqlite3)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_sqlite>=5.4.0:../../databases/php-pdo_sqlite
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_pgsql>=5.4.0:../../databases/php-pdo_pgsql
.endif
