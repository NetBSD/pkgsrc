# $NetBSD: Makefile,v 1.11 2012/06/16 03:02:32 taca Exp $

MODNAME=		intl
PKGREVISION=		1
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
LICENSE=		php

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/phpversion.mk"

# PHP 5.2.x needs pecl version
.if ${PKG_PHP_VERSION} == 52 
PECL_VERSION=		2.0.0
PECL_LEGACY_VERSION_SCHEME=	yes
.else
PATCHDIR=		# ignore patch in current directory
.endif

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
