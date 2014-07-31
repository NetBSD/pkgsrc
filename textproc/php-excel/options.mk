# $NetBSD: options.mk,v 1.1 2014/07/31 00:00:32 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-excel
PKG_SUPPORTED_OPTIONS=	gd zip
PKG_SUGGESTED_OPTIONS+=	gd zip

.include "../../mk/bsd.options.mk"

.include "../../lang/php/phpversion.mk"

.if !empty(PKG_OPTIONS:Mgd)
DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd
.endif

.if !empty(PKG_OPTIONS:Mzip)
DEPENDS+=	${PHP_PKG_PREFIX}-zip-[0-9]*:../../archivers/php-zip
.endif
