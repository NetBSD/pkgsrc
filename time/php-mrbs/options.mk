# $NetBSD: options.mk,v 1.4 2019/11/02 16:28:41 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-mrbs

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql

PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### Use mysql, or pgsql backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=		${PHP_PKG_PREFIX}-mysql>=5.2.0:../../databases/php-mysql
PHP_VERSIONS_ACCEPTED=	56
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=		${PHP_PKG_PREFIX}-pgsql>=5.2.0:../../databases/php-pgsql
.else
PKG_FAIL_REASON+=	${PKGNAME} needs either mysql or pgsql
.endif
