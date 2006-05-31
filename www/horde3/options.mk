# $NetBSD: options.mk,v 1.5 2006/05/31 18:22:26 ghen Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.horde
PKG_SUPPORTED_OPTIONS=	ldap pgsql mysql
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### Use OpenLDAP for storing user details
###
.if !empty(PKG_OPTIONS:Mldap)
.	include "../../databases/openldap-client/buildlink3.mk"
DEPENDS+=	php-ldap>=4.3.3:../../databases/php-ldap
.endif

###
### Use PostgreSQL for storing user details
###
.if !empty(PKG_OPTIONS:Mpgsql)
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
