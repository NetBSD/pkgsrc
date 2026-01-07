# $NetBSD: Makefile,v 1.59 2026/01/07 08:49:06 wiz Exp $

MODNAME=		intl
PKGREVISION=		17
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
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
