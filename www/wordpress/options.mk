# $NetBSD: options.mk,v 1.1.1.1 2009/04/06 11:31:02 adrianp Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wordpress

PKG_OPTIONS_REQUIRED_GROUPS=	wordpress
PKG_OPTIONS_GROUP.wordpress=	php-cgi ap-php

PKG_SUGGESTED_OPTIONS=		ap-php

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mphp-cgi)
.  if ${PKG_PHP_VERSION} == "4"
DEPENDS+=	php>=4.4.7:../../www/php4
.  endif
.  if ${PKG_PHP_VERSION} == "5"
DEPENDS+=	php>=5.2.4:../../lang/php5
.  endif
.endif

.if !empty(PKG_OPTIONS:Map-php)
.  include "../../mk/apachever.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.0:../../www/ap-php
.endif
