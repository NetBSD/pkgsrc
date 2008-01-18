# $NetBSD: Makefile,v 1.13 2008/01/18 05:09:52 tnn Exp $

MODNAME=		curl
PKGREVISION=		2
CATEGORIES+=		www
COMMENT=		PHP extension for curl functions

CONFLICTS=	php-curl-[0-9]*

CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_PREFIX.curl}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
