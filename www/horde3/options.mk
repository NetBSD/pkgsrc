# $NetBSD: options.mk,v 1.1.1.1 2005/01/16 21:10:16 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.horde
PKG_SUPPORTED_OPTIONS=	ldap postgresql73 postgresql74 mysql

.if !defined(PKG_OPTIONS.horde)
PKG_DEFAULT_OPTIONS+=	mysql
.endif
.include "../../mk/bsd.options.mk"

###
### Can't support both versions of PostgreSQL
###
.if !empty(PKG_OPTIONS:Mpostgresql73) && !empty(PKG_OPTIONS:Mpostgresql74)
PKG_FAIL_REASON+=	"PostgreSQL 7.3 and 7.4 cannot both be compiled in." \
			"Please change ${PKG_OPTIONS_VAR} to one or the other."
.endif

###
### Use OpenLDAP for storing user details
###
.if !empty(PKG_OPTIONS:Mldap)
.	include "../../databases/openldap/buildlink3.mk"
DEPENDS+=	php-ldap>=4.3.3:../../databases/php-ldap
.endif

###
### Use PostgreSQL v7.3 for storing user details
###
.if !empty(PKG_OPTIONS:Mpostgresql73)
.	include "../../databases/postgresql73-lib/buildlink3.mk"
DEPENDS+=	php-pgsql>=4.3.3:../../databases/php-pgsql
.endif

###
### Use PostgreSQL v7.4 for storing user details
###
.if !empty(PKG_OPTIONS:Mpostgresql74)
.	include "../../databases/postgresql74-lib/buildlink3.mk"
DEPENDS+=	php-pgsql>=4.3.3:../../databases/php-pgsql
.endif

###
### Use MySQL for storing user details
###
.if !empty(PKG_OPTIONS:Mmysql)
.	include "../../mk/mysql.buildlink3.mk"
DEPENDS+=	php-mysql>=4.3.3:../../databases/php-mysql
.endif
