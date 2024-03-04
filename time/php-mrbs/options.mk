# $NetBSD: options.mk,v 1.6 2024/03/04 10:21:34 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-mrbs

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql
PKG_SUGGESTED_OPTIONS=		mysql

.include "../../mk/bsd.options.mk"

###
### Use mysql, or pgsql backend
###
.if ${PKG_OPTIONS:Mmysql}
DEPENDS+=		${PHP_PKG_PREFIX}-pdo_mysql>=${PHP_BASE_VERS}:../../databases/php-pdo_mysql
.elif ${PKG_OPTIONS:Mpgsql}
DEPENDS+=		${PHP_PKG_PREFIX}-pdo_pgsql>=${PHP_BASE_VERS}:../../databases/php-pdo_pgsql
.endif
