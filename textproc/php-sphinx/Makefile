# $NetBSD: Makefile,v 1.2 2015/12/25 01:18:10 taca Exp $

MODNAME=		sphinx
PECL_VERSION=		1.3.3
CATEGORIES+=		textproc databases

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/sphinx/
COMMENT=		Client extension for Sphinx
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	55 56

CONFIGURE_ARGS+=	--with-sphinx=${BUILDLINK_PREFIX.sphinxsearch}

.include "../../lang/php/ext.mk"
.include "../../textproc/sphinxsearch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
