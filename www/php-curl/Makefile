# $NetBSD: Makefile,v 1.67 2026/01/07 08:49:24 wiz Exp $

MODNAME=		curl
PKGREVISION=		26
CATEGORIES+=		www
COMMENT=		PHP extension for curl functions

CONFLICTS=	php-curl-[0-9]*

CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_PREFIX.curl}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
