# $NetBSD: Makefile,v 1.2 2016/08/11 22:54:16 jdolecek Exp $

MODNAME=	apcu_bc
PKGMODNAME= apc
PECL_VERSION=	1.0.3
CATEGORIES+=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	APCu  Backwards Compatibility Module
LICENSE=	php

PHP_VERSIONS_ACCEPTED=	70 71

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../www/php-apcu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
