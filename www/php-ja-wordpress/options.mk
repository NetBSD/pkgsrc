# $NetBSD: options.mk,v 1.3 2019/12/16 16:52:40 taca Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wordpress

PKG_OPTIONS_REQUIRED_GROUPS=	wordpress
PKG_OPTIONS_GROUP.wordpress=	php-cgi ap-php php-fpm

PKG_SUGGESTED_OPTIONS=		php-fpm

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mphp-cgi)
DEPENDS+=	php>=5.6.0:${PHPPKGSRCDIR}
.endif

.if !empty(PKG_OPTIONS:Map-php)
.  include "../../mk/apache.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=5.6.0:../../www/ap-php
.endif

.if !empty(PKG_OPTIONS:Mphp-fpm)
DEPENDS+=	${PHP_PKG_PREFIX}-fpm>=5.6.0:../../www/php-fpm
.endif
