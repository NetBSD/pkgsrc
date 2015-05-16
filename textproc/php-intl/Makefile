# $NetBSD: Makefile,v 1.19 2015/05/16 11:19:53 taca Exp $

MODNAME=		intl
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
LICENSE=		php

USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
