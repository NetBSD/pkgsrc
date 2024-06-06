# $NetBSD: Makefile,v 1.53 2024/06/06 12:08:53 jperkin Exp $

MODNAME=		intl
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
PKGREVISION=		12
LICENSE=		php

USE_LANGUAGES=		c c++
USE_PHP_EXT_PATCHES=	yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}
CPPFLAGS+=		-DU_USING_ICU_NAMESPACE=1

FORCE_CXX_STD+=		c++17

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
