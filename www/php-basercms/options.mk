# $NetBSD: options.mk,v 1.1 2013/11/22 14:35:56 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-basercms

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		csv mysql pgsql sqlite

PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### Use csv, mysql, pgsql, or sqlite backend
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
.elif !!empty(PKG_OPTIONS:Mcsv)
# no DEPENDS
.endif
