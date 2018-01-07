# $NetBSD: Makefile,v 1.33.2.1 2018/01/07 18:02:30 bsiegert Exp $

MODNAME=		intl
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
LICENSE=		php

USE_LANGUAGES=		c c++11
USE_PHP_EXT_PATCHES=	yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

GCC_REQD+=		4.7 # minimum for -std=c++11

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
