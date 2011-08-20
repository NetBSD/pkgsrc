# $NetBSD: Makefile,v 1.1.1.1 2011/08/20 14:53:29 taca Exp $

MODNAME=		tidy
CATEGORIES+=		www
COMMENT=		PHP extension for tidy functions
LICENSE=		php

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-tidy=shared,${BUILDLINK_PREFIX.tidy}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../www/tidy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
