# $NetBSD: options.mk,v 1.2 2009/07/24 11:44:51 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mediawiki

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql

PKG_SUPPORTED_OPTIONS+=	mysql pgsql
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### Use mysql or postgresql backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.10:../../databases/php-mysql
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=5:../../databases/php-pgsql
.endif
