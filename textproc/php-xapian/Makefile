# $NetBSD: Makefile,v 1.2 2021/12/14 08:47:06 schmonz Exp $

PKGNAME=		${PHP_PKG_PREFIX}-${PKGNAME_MODULE}
COMMENT=		PHP bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/php/

.include "../../lang/php/phpversion.mk"

PHP_VERSIONS_INCOMPATIBLE=	80 81

.if (${PKG_PHP_MAJOR_VERS} == 5)
CONFIGURE_ARGS+=	--with-php
PHP_5_OR_EMPTY=		5
.else
CONFIGURE_ARGS+=	--with-php7
PHP_5_OR_EMPTY=		# empty
.endif

PLIST_SUBST+=		PHP_5_OR_EMPTY=${PHP_5_OR_EMPTY:Q}

.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
