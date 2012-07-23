# $NetBSD: Makefile,v 1.12.2.1 2012/07/23 18:24:34 tron Exp $

MODNAME=		intl
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
LICENSE=		php

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
