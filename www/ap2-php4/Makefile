# $NetBSD: Makefile,v 1.4 2003/08/23 14:22:45 grant Exp $

PKGNAME=		ap2-php-${PHP_BASE_VERS}
PKGREVISION=		# empty
COMMENT=		Apache 2.x module for PHP4

DEPENDS+=		php>=${PHP_BASE_VERS}:../../www/php4

USE_BUILDLINK2=		YES
APACHE_MODULE=		YES

.include "../../www/php4/Makefile.php"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

# Needed to pickup includes
CFLAGS+=		-I${PREFIX}/include/apr-0

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so	\
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../www/apache2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
