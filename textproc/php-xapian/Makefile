# $NetBSD: Makefile,v 1.1 2017/07/10 17:34:04 schmonz Exp $

PKGNAME=		${PHP_PKG_PREFIX}-${PKGNAME_MODULE}
COMMENT=		PHP bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/php/

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
