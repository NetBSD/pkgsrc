# $NetBSD: Makefile,v 1.10 2012/04/27 12:32:04 obache Exp $

MODNAME=		intl
PECL_VERSION=		2.0.0
PECL_LEGACY_VERSION_SCHEME=	yes
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
