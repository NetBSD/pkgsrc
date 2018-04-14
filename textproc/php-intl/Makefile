# $NetBSD: Makefile,v 1.35 2018/04/14 07:34:42 adam Exp $

MODNAME=		intl
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
PKGREVISION=		1
LICENSE=		php

USE_LANGUAGES=		c c++11
USE_PHP_EXT_PATCHES=	yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

GCC_REQD+=		4.7 # minimum for -std=c++11

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
