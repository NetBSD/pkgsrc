# $NetBSD: Makefile,v 1.18 2012/07/20 12:30:38 taca Exp $

MODNAME=		curl
CATEGORIES+=		www
COMMENT=		PHP extension for curl functions

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-curl-[0-9]*

CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_PREFIX.curl}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
