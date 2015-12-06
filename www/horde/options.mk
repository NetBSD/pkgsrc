# $NetBSD: options.mk,v 1.3 2015/12/06 12:13:13 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.horde
PKG_SUPPORTED_OPTIONS=	ldap pgsql mysql
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### Use OpenLDAP for storing user details
###
.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=4.3.3:../../databases/php-ldap
.endif

###
### Use PostgreSQL for storing user details
###
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=4.3.3:../../databases/php-pgsql
.endif

###
### Use MySQL for storing user details
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql
PHP_VERSIONS_ACCEPTED=	55 56
.endif
