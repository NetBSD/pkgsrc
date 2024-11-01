# $NetBSD: Makefile,v 1.61 2024/11/01 12:54:55 wiz Exp $

MODNAME=		curl
CATEGORIES+=		www
COMMENT=		PHP extension for curl functions
PKGREVISION=		20

CONFLICTS=	php-curl-[0-9]*

CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_PREFIX.curl}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
