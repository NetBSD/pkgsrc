# $NetBSD: options.mk,v 1.5 2016/08/22 18:11:04 morr Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wordpress

PKG_OPTIONS_REQUIRED_GROUPS=	wordpress
PKG_OPTIONS_GROUP.wordpress=	php-cgi ap-php

PKG_SUGGESTED_OPTIONS=		ap-php

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mphp-cgi)
DEPENDS+=	php>=5.6.0:${PHPPKGSRCDIR}
.endif

.if !empty(PKG_OPTIONS:Map-php)
.  include "../../mk/apache.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=5.6.0:../../www/ap-php
.endif
