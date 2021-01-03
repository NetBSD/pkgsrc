# $NetBSD: Makefile,v 1.9 2021/01/03 15:26:12 taca Exp $

MODNAME=	apcu_bc
PKGMODNAME=	apc
PECL_VERSION=	1.0.5
CATEGORIES+=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	APCu  Backwards Compatibility Module
LICENSE=	php

PHP_VERSIONS_ACCEPTED=	73 74

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../www/php-apcu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
