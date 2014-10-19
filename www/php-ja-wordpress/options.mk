# $NetBSD: options.mk,v 1.2 2014/10/19 14:14:47 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wordpress

PKG_OPTIONS_REQUIRED_GROUPS=	wordpress
PKG_OPTIONS_GROUP.wordpress=	php-cgi ap-php php-fpm

PKG_SUGGESTED_OPTIONS=		php-fpm

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mphp-cgi)
DEPENDS+=	php>=5.2.4:${PHPPKGSRCDIR}
.endif

.if !empty(PKG_OPTIONS:Map-php)
.  include "../../mk/apache.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.0:../../www/ap-php
.endif

.if !empty(PKG_OPTIONS:Mphp-fpm)
DEPENDS+=	${PHP_PKG_PREFIX}-fpm>=5.2.4:../../www/php-fpm
.endif
