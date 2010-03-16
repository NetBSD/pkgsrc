# $NetBSD: options.mk,v 1.5 2010/03/16 16:02:21 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.drupal

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql

PKG_SUPPORTED_OPTIONS=	drupal-xmlservices apache unicode
PKG_SUGGESTED_OPTIONS=	mysql drupal-xmlservices apache

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
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom
.endif

###
### Support for unicode
###
.if !empty(PKG_OPTIONS:Municode)
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=4.3.3:../../converters/php-mbstring
.endif

###
### Drupal can run on a number of web servers, we support apache by default
###
.if !empty(PKG_OPTIONS:Mapache)
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.5:../../www/ap-php
.	include "../../mk/apachever.mk"
WWW_USER?=	${APACHE_USER}
WWW_GROUP?=	${APACHE_GROUP}
.else
WWW_USER?=	${ROOT_USER}
WWW_GROUP?=	${ROOT_GROUP}
.endif
