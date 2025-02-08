# $NetBSD: Makefile,v 1.7 2025/02/08 03:55:19 taca Exp $

PKGNAME=		${PHP_PKG_PREFIX}-${PKGNAME_MODULE}
PKGREVISION=		1
COMMENT=		PHP bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/php/

PHP_VERSIONS_INCOMPATIBLE=	56 74

CONFIGURE_ARGS+=	--with-php
CONFIGURE_ENV+=		PHP_CONFIG=${PHP_CONFIG}

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
