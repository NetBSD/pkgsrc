# $NetBSD: Makefile,v 1.7 2020/11/21 14:52:58 otis Exp $
#

MODNAME=		phalcon
PECL_VERSION=		3.4.5
PKGNAME=		${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=phalcon/}
EXTRACT_SUFX=		.tar.gz

HOMEPAGE=		https://phalconphp.com/
COMMENT=		Web framework implemented as a C extension offering high performance
LICENSE=		php

GITHUB_PROJECT=		cphalcon
GITHUB_TAG=		v${PKGVERSION_NOREV}

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

BUILD_DEPENDS+=		re2c>=0.15.3:../../devel/re2c
DEPENDS+=		${PHP_PKG_PREFIX}-curl>=5.6.0:../../www/php-curl
DEPENDS+=		${PHP_PKG_PREFIX}-gd>=5.6.0:../../graphics/php-gd
DEPENDS+=		${PHP_PKG_PREFIX}-json>=5.6.0:../../textproc/php-json
DEPENDS+=		${PHP_PKG_PREFIX}-mbstring>=5.6.0:../../converters/php-mbstring
DEPENDS+=		${PHP_PKG_PREFIX}-pdo>=5.6.0:../../databases/php-pdo
DEPENDS+=		${PHP_PKG_PREFIX}-pdo_mysql>=5.6.0:../../databases/php-pdo_mysql

.include "../../lang/php/phpversion.mk"

PHPSETUPSUBDIR=		build/php${PKG_PHP_MAJOR_VERS}/${"${MACHINE_ARCH:Mx86_64}":?64:32}bits
MODULESDIR=		${WRKSRC}/${PHPSETUPSUBDIR}/modules
CONFIGURE_DIRS+=	${PHPSETUPSUBDIR}

.include "../../databases/php-pdo/buildlink3.mk"
.include "../../textproc/php-json/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
