# $NetBSD: Makefile,v 1.23 2002/09/04 14:47:39 agc Exp $

PKGNAME=		ap-php-${PHP_BASE_VERS}
PKGREVISION=		# empty
COMMENT=		Apache module for PHP4

DEPENDS+=		php>=${PHP_BASE_VERS}:../../www/php4

USE_BUILDLINK2=		YES
APACHE_MODULE=		YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so	\
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../www/apache/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
