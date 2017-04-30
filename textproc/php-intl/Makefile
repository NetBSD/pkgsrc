# $NetBSD: Makefile,v 1.28 2017/04/30 22:49:54 maya Exp $

MODNAME=		intl
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
PKGREVISION=		1
LICENSE=		php

CXXFLAGS+=		-std=c++11
USE_LANGUAGES=		c c++
USE_PHP_EXT_PATCHES=	yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
