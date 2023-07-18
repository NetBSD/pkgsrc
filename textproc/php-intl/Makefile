# $NetBSD: Makefile,v 1.50 2023/07/18 18:47:53 nia Exp $

MODNAME=		intl
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
PKGREVISION=		10
LICENSE=		php

USE_LANGUAGES=		c c++
USE_PHP_EXT_PATCHES=	yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}
CPPFLAGS+=		-DU_USING_ICU_NAMESPACE=1

USE_CXX_FEATURES+=	c++11

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
