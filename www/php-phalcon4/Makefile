# $NetBSD: Makefile,v 1.5 2025/02/08 04:07:18 taca Exp $
#

MODNAME=		phalcon
PECL_VERSION=		4.1.0
PKGREVISION=		1
PKGNAME=		${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=phalcon/}
EXTRACT_SUFX=		.tar.gz

HOMEPAGE=		https://phalconphp.com/
COMMENT=		Web framework implemented as a C extension offering high performance
LICENSE=		php

CONFLICTS=		php-phalcon-[0-9]*

PHP_VERSIONS_ACCEPTED=  74

GITHUB_PROJECT=		cphalcon
GITHUB_TAG=		v${PKGVERSION_NOREV}

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

TOOL_DEPENDS+=		re2c>=0.15.3:../../devel/re2c
DEPENDS+=		${PHP_PKG_PREFIX}-curl>=${PHP_BASE_VERS}:../../www/php-curl
DEPENDS+=		${PHP_PKG_PREFIX}-gettext>=${PHP_BASE_VERS}:../../devel/php-gettext
DEPENDS+=		${PHP_PKG_PREFIX}-json>=${PHP_BASE_VERS}:../../textproc/php-json
DEPENDS+=		${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=		${PHP_PKG_PREFIX}-pdo>=${PHP_BASE_VERS}:../../databases/php-pdo
DEPENDS+=		${PHP_PKG_PREFIX}-psr>=1.0.0:../../devel/php-psr

.include "../../lang/php/phpversion.mk"

PHPSETUPSUBDIR=		build/php${PHP_MAJOR_VERS}/${"${MACHINE_ARCH:Mx86_64}":?64:32}bits
MODULESDIR=		${WRKSRC}/${PHPSETUPSUBDIR}/modules
CONFIGURE_DIRS+=	${PHPSETUPSUBDIR}

.include "../../databases/php-pdo/buildlink3.mk"
.include "../../textproc/php-json/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
