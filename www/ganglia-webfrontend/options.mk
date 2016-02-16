# $NetBSD: options.mk,v 1.1 2016/02/16 13:05:23 fhajny Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ganglia-webfrontend

PKG_OPTIONS_REQUIRED_GROUPS=	webserver
PKG_OPTIONS_GROUP.webserver=	apache nginx

PKG_SUPPORTED_OPTIONS=		#
PKG_SUGGESTED_OPTIONS=		apache

.include "../../mk/bsd.options.mk"

###
### Use apache web server
###
.if !empty(PKG_OPTIONS:Mapache)
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.1:../../www/ap-php
WWW_USER?=		${APACHE_USER}
WWW_GROUP?=		${APACHE_GROUP}
BUILD_DEFS+=		APACHE_USER APACHE_GROUP
.include "../../mk/apache.mk"
.endif

###
### Use nginx web server
###
.if !empty(PKG_OPTIONS:Mnginx)
DEPENDS+=	nginx-[0-9]*:../../www/nginx
NGINX_USER?=		nginx
NGINX_GROUP?=		nginx
WWW_USER?=		${NGINX_USER}
WWW_GROUP?=		${NGINX_USER}
BUILD_DEFS+=		NGINX_USER NGINX_GROUP
.endif
