# $NetBSD: options.mk,v 1.2 2005/03/04 22:35:22 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.horde
PKG_SUPPORTED_OPTIONS=	ldap postgresql mysql

.if !defined(PKG_OPTIONS.horde)
PKG_DEFAULT_OPTIONS+=	mysql
.endif
.include "../../mk/bsd.options.mk"

###
### Use OpenLDAP for storing user details
###
.if !empty(PKG_OPTIONS:Mldap)
.	include "../../databases/openldap/buildlink3.mk"
DEPENDS+=	php-ldap>=4.3.3:../../databases/php-ldap
.endif

###
### Use PostgreSQL for storing user details
###
.if !empty(PKG_OPTIONS:Mpostgresql)
.	include "../../mk/pgsql.buildlink3.mk"
DEPENDS+=	php-pgsql>=4.3.3:../../databases/php-pgsql
.endif

###
### Use MySQL for storing user details
###
.if !empty(PKG_OPTIONS:Mmysql)
.	include "../../mk/mysql.buildlink3.mk"
DEPENDS+=	php-mysql>=4.3.3:../../databases/php-mysql
.endif
