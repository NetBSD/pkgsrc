# $NetBSD: Makefile,v 1.6 2020/11/21 13:57:21 otis Exp $
#

MODNAME=		phalcon
PECL_VERSION=		4.1.0
PKGNAME=		${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=phalcon/}
EXTRACT_SUFX=		.tar.gz

HOMEPAGE=		https://phalconphp.com/
COMMENT=		Web framework implemented as a C extension offering high performance
LICENSE=		php

CONFLICTS=		php-phalcon-[0-9]*

PHP_VERSIONS_ACCEPTED=  72 73 74

GITHUB_PROJECT=		cphalcon
GITHUB_TAG=		v${PKGVERSION_NOREV}

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

BUILD_DEPENDS+=		re2c>=0.15.3:../../devel/re2c
DEPENDS+=		${PHP_PKG_PREFIX}-curl>=7.2.0:../../www/php-curl
DEPENDS+=		${PHP_PKG_PREFIX}-gettext>=7.2.0:../../devel/php-gettext
DEPENDS+=		${PHP_PKG_PREFIX}-json>=7.2.0:../../textproc/php-json
DEPENDS+=		${PHP_PKG_PREFIX}-mbstring>=7.2.0:../../converters/php-mbstring
DEPENDS+=		${PHP_PKG_PREFIX}-pdo>=7.2.0:../../databases/php-pdo
DEPENDS+=		${PHP_PKG_PREFIX}-psr>=1.0.0:../../devel/php-psr

.include "../../lang/php/phpversion.mk"

PHPSETUPSUBDIR=		build/php${PKG_PHP_MAJOR_VERS}/${"${MACHINE_ARCH:Mx86_64}":?64:32}bits
MODULESDIR=		${WRKSRC}/${PHPSETUPSUBDIR}/modules
CONFIGURE_DIRS+=	${PHPSETUPSUBDIR}

.include "../../databases/php-pdo/buildlink3.mk"
.include "../../textproc/php-json/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
