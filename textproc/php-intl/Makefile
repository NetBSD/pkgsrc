# $NetBSD: Makefile,v 1.16 2014/10/07 16:47:36 adam Exp $

MODNAME=		intl
PKGREVISION=		2
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
LICENSE=		php

USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
