# $NetBSD: Makefile,v 1.1 2015/10/22 10:53:01 fhajny Exp $

MODNAME=		sphinx
PECL_VERSION=		1.3.3
CATEGORIES+=		textproc databases

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/sphinx/
COMMENT=		Client extension for Sphinx
LICENSE=		php

CONFIGURE_ARGS+=	--with-sphinx=${BUILDLINK_PREFIX.sphinxsearch}

.include "../../lang/php/ext.mk"
.include "../../textproc/sphinxsearch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
