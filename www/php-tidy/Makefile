# $NetBSD: Makefile,v 1.3 2017/02/20 09:37:12 wiz Exp $

MODNAME=		tidy
CATEGORIES+=		www
COMMENT=		PHP extension for tidy functions
PKGREVISION=		1
LICENSE=		php

CONFIGURE_ARGS+=	--with-tidy=shared,${BUILDLINK_PREFIX.tidy}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../www/tidy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
