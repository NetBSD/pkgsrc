# $NetBSD: options.mk,v 1.3 2016/09/11 17:03:29 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-tt-rss

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql

PKG_SUGGESTED_OPTIONS=	pgsql

.include "../../mk/bsd.options.mk"

###
### Use mysql or pgsql backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.2.0:../../databases/php-mysql
PHP_VERSIONS_ACCEPTED=	56
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=5.2.0:../../databases/php-pgsql
.endif
