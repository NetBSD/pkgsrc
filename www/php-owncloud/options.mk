# $NetBSD: options.mk,v 1.1 2011/12/18 08:38:14 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-owncloud

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql sqlite

PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

###
### Use mysql or sqlite backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.2.0:../../databases/php-mysql
.elif !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PHP_PKG_PREFIX}-sqlite>=5.2.0:../../databases/php-sqlite
.endif
