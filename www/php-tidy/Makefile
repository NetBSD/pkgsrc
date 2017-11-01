# $NetBSD: Makefile,v 1.3.8.1 2017/11/01 19:19:24 spz Exp $

MODNAME=		tidy
CATEGORIES+=		www
COMMENT=		PHP extension for tidy functions
LICENSE=		php

CONFIGURE_ARGS+=	--with-tidy=shared,${BUILDLINK_PREFIX.tidy}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../www/tidy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
