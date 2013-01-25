# $NetBSD: options.mk,v 1.4 2013/01/25 20:02:24 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-owncloud

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql sqlite pgsql

PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

###
### Use mysql, pgsql, or sqlite backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.2.0:../../databases/php-mysql
.elif !empty(PKG_OPTIONS:Msqlite)

# php-sqlite provides sqlite2
#DEPENDS+=	${PHP_PKG_PREFIX}-sqlite>=5.2.0:../../databases/php-sqlite

# php-pdo_sqlite provides sqlite3.  An owncloud instance that was
# installed as version 2 and upgraded to 3 and then 4
# complained/failed that PDO was not present.
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_sqlite>=5.2.0:../../databases/php-pdo_sqlite
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=5.2.0:../../databases/php-pgsql
.endif
