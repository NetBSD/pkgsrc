# $NetBSD: options.mk,v 1.7 2026/03/08 13:45:27 taca Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wordpress
PKG_SUPPORTED_OPTIONS=		ap-php php-fpm
PKG_SUGGESTED_OPTIONS=		ap-php

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Map-php)
.  include "../../mk/apache.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=${PHP_BASE_VERS}:../../www/ap-php
.endif

.if !empty(PKG_OPTIONS:Mphp-fpm)
DEPENDS+=	${PHP_PKG_PREFIX}-fpm>=${PHP_BASE_VERS}:../../www/php-fpm
.endif
