# $NetBSD: Makefile,v 1.31 2017/09/18 09:53:36 maya Exp $

MODNAME=		intl
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
PKGREVISION=		2
LICENSE=		php

USE_LANGUAGES=		c c++11
USE_PHP_EXT_PATCHES=	yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

GCC_REQD+=		4.7 # minimum for -std=c++11

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
