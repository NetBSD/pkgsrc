# $NetBSD: options.mk,v 1.5 2024/02/28 16:41:42 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-mrbs

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql
PKG_SUGGESTED_OPTIONS=		mysql

.include "../../mk/bsd.options.mk"

###
### Use mysql, or pgsql backend
###
.if ${PKG_OPTIONS:Mmysql}
DEPENDS+=		${PHP_PKG_PREFIX}-pdo_mysql>=7.4.0:../../databases/php-pdo_mysql
.elif ${PKG_OPTIONS:Mpgsql}
DEPENDS+=		${PHP_PKG_PREFIX}-pdo_pgsql>=7.4.0:../../databases/php-pdo_pgsql
.endif
