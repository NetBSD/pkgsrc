# $NetBSD: Makefile,v 1.5 2019/11/04 22:10:11 rillig Exp $

MODNAME=	apcu_bc
PKGMODNAME=	apc
PECL_VERSION=	1.0.3
CATEGORIES+=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	APCu  Backwards Compatibility Module
LICENSE=	php

PHP_VERSIONS_ACCEPTED=	71 72

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../www/php-apcu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
