# $NetBSD: Makefile,v 1.8 2025/05/09 20:01:32 schmonz Exp $

PKGNAME=		${PHP_PKG_PREFIX}-${PKGNAME_MODULE}
COMMENT=		PHP bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/php/

PHP_VERSIONS_INCOMPATIBLE=	56 74

CONFIGURE_ARGS+=	--with-php
CONFIGURE_ENV+=		PHP_CONFIG=${PHP_CONFIG}

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
