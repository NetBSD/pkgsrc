# $NetBSD: options.mk,v 1.3 2012/12/20 12:45:58 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.drupal

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql sqlite

PKG_SUPPORTED_OPTIONS=	drupal-xmlservices apache unicode
PKG_SUGGESTED_OPTIONS=	mysql drupal-xmlservices apache

.include "../../mk/bsd.options.mk"

###
### Use PostgreSQL for storing Drupal data
###
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_pgsql>=5.2.7:../../databases/php-pdo_pgsql
.elif !empty(PKG_OPTIONS:Mmysql)
###
### Use MySQL for storing Drupal data
###
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=5.2.7:../../databases/php-pdo_mysql
.elif !empty(PKG_OPTIONS:Msqlite)
###
### Use SQLite for storing Drupal data
###
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_sqlite>=5.2.7:../../databases/php-pdo_sqlite
.endif

###
### Enable XML-based services such as the Blogger API, Jabber and RSS
### syndication.
###
.if !empty(PKG_OPTIONS:Mdrupal-xmlservices)
DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.2.7:../../textproc/php-dom
.endif

###
### Support for unicode
###
.if !empty(PKG_OPTIONS:Municode)
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.2.7:../../converters/php-mbstring
.endif

###
### Drupal can run on a number of web servers, we support apache by default
###
.if !empty(PKG_OPTIONS:Mapache)
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=5.2.7:../../www/ap-php
.	include "../../mk/apache.mk"
WWW_USER?=	${APACHE_USER}
WWW_GROUP?=	${APACHE_GROUP}
.else
WWW_USER?=	${ROOT_USER}
WWW_GROUP?=	${ROOT_GROUP}
.endif
