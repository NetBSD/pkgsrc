# $NetBSD: Makefile,v 1.47 2022/04/18 19:12:11 adam Exp $

MODNAME=		intl
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
PKGREVISION=		8
LICENSE=		php

USE_LANGUAGES=		c c++11
USE_PHP_EXT_PATCHES=	yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}
CPPFLAGS+=		-DU_USING_ICU_NAMESPACE=1

GCC_REQD+=		4.7 # minimum for -std=c++11

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
