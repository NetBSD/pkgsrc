# $NetBSD: options.mk,v 1.6 2017/04/15 15:42:32 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mediawiki

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql

PKG_SUPPORTED_OPTIONS+=	apache mysql pgsql
PKG_SUGGESTED_OPTIONS=	apache mysql

.include "../../mk/bsd.options.mk"

###
### Use mysql or postgresql backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=5.5.9:../../databases/php-mysqli
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=5:../../databases/php-pgsql
.endif

.if !empty(PKG_OPTIONS:Mapache)
.include "../../mk/apache.mk"
.endif
