# $NetBSD: options.mk,v 1.2 2015/01/08 13:35:03 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-basercms

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		csv mysql pgsql sqlite

PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### Use csv, mysql, pgsql, or sqlite backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=5.2.0:../../databases/php-pdo_mysql
.elif !empty(PKG_OPTIONS:Msqlite)

# php-pdo_sqlite provides sqlite3.  An owncloud instance that was
# installed as version 2 and upgraded to 3 and then 4
# complained/failed that PDO was not present.
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_sqlite>=5.2.0:../../databases/php-pdo_sqlite
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_pgsql>=5.2.0:../../databases/php-pdo_pgsql
.elif !!empty(PKG_OPTIONS:Mcsv)
# no DEPENDS
.endif
