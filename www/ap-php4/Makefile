# $NetBSD: Makefile,v 1.29 2003/08/23 14:22:44 grant Exp $
#

PKGNAME=		ap-php-${PHP_BASE_VERS}
PKGREVISION=		1
COMMENT=		Apache 1.x module for PHP4

DEPENDS+=		php>=${PHP_BASE_VERS}:../../www/php4

USE_BUILDLINK2=		YES
APACHE_MODULE=		YES
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../www/php4/Makefile.php"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so	\
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../www/apache/buildlink2.mk"

.include "../../mk/gcc.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
