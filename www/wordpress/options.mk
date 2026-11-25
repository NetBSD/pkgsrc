# $NetBSD: options.mk,v 1.9 2026/11/25 17:16:37 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wordpress
PKG_SUPPORTED_OPTIONS=		ap-php php-fpm
PKG_SUGGESTED_OPTIONS=		ap-php

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Map-php)
.include "../../www/apache24/buildlink3.mk"
DEPENDS+=	ap24-${PHP_PKG_PREFIX}>=${PHP_BASE_VERS}:../../www/ap-php
.endif

.if !empty(PKG_OPTIONS:Mphp-fpm)
DEPENDS+=	${PHP_PKG_PREFIX}-fpm>=${PHP_BASE_VERS}:../../www/php-fpm
.endif
