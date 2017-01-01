# $NetBSD: Makefile,v 1.29 2017/01/01 16:06:39 adam Exp $

MODNAME=		curl
CATEGORIES+=		www
COMMENT=		PHP extension for curl functions
PKGREVISION=		1

CONFLICTS=	php-curl-[0-9]*

CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_PREFIX.curl}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
