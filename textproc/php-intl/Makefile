# $NetBSD: Makefile,v 1.12 2012/06/18 15:16:49 taca Exp $

MODNAME=		intl
PKGREVISION=		1
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
LICENSE=		php

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
