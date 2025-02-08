# $NetBSD: Makefile,v 1.5 2025/02/08 03:22:19 taca Exp $

MODNAME=		tidy
PKGREVISION=		1
CATEGORIES+=		www
COMMENT=		PHP extension for tidy functions
LICENSE=		php

CONFIGURE_ARGS+=	--with-tidy=shared,${BUILDLINK_PREFIX.tidy}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../www/tidy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
