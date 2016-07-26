# $NetBSD: Makefile,v 1.1.1.1 2016/07/26 09:26:06 jdolecek Exp $

MODNAME=	apcu_bc
PKGMODNAME= apc
PECL_VERSION=	1.0.3
CATEGORIES+=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	APCu  Backwards Compatibility Module
LICENSE=	php

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../www/php-apcu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
