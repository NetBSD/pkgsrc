# $NetBSD: options.mk,v 1.4 2010/03/15 16:48:53 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.drupal

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql

PKG_SUPPORTED_OPTIONS=	drupal-xmlservices
PKG_SUGGESTED_OPTIONS=	mysql drupal-xmlservices

.include "../../mk/bsd.options.mk"

###
### Use PostgreSQL for storing Drupal data
###
.if !empty(PKG_OPTIONS:Mpgsql)
.	include "../../mk/pgsql.buildlink3.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql-[0-9]*:../../databases/php-pgsql
.elif !empty(PKG_OPTIONS:Mmysql)
###
### Use MySQL for storing Drupal data
###
.	include "../../mk/mysql.buildlink3.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql
.endif

###
### Enable XML-based services such as the Blogger API, Jabber and RSS
### syndication.
###
.if !empty(PKG_OPTIONS:Mdrupal-xmlservices)
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php5-dom
.endif
