# $NetBSD: options.mk,v 1.1 2022/12/23 13:47:42 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.geeklog

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql

PKG_SUPPORTED_OPTIONS=	mysql pgsql
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### Use mysql or postgresql backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=7.4.0:../../databases/php-mysqli
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=7.4.0:../../databases/php-pgsql
.endif
