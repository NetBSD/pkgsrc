# $NetBSD: Makefile,v 1.6 2023/02/04 14:28:19 schmonz Exp $

PKGNAME=		${PHP_PKG_PREFIX}-${PKGNAME_MODULE}
COMMENT=		PHP bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/php/

PHP_VERSIONS_INCOMPATIBLE=	56 74

.include "../../lang/php/phpversion.mk"

CONFIGURE_ARGS+=	--with-php

.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
