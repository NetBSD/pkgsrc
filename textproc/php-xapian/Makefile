# $NetBSD: Makefile,v 1.4 2022/09/24 19:09:19 schmonz Exp $

PKGNAME=		${PHP_PKG_PREFIX}-${PKGNAME_MODULE}
COMMENT=		PHP bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/php/

# https://trac.xapian.org/ticket/817
PHP_VERSIONS_INCOMPATIBLE=	80 81

.include "../../lang/php/phpversion.mk"

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
