# $NetBSD: Makefile,v 1.8 2021/12/13 14:46:09 taca Exp $
#

MODNAME=	uploadprogress
PECL_VERSION=	2.0.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP extension to track progress of a file upload
LICENSE=	php

PHP_VERSIONS_INCOMPATIBLE=	56

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
