# $NetBSD: Makefile,v 1.14 2008/06/12 02:14:56 joerg Exp $

MODNAME=		curl
PKGREVISION=		2
CATEGORIES+=		www
COMMENT=		PHP extension for curl functions

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-curl-[0-9]*

CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_PREFIX.curl}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
