# $NetBSD: Makefile,v 1.22 2002/08/25 21:51:51 jlam Exp $

PKGNAME=		ap-php-${PHP_BASE_VERS}
PKGREVISION=		# empty
COMMENT=		Apache module for PHP4

DEPENDS+=		php>=${PHP_BASE_VERS}:../../www/php4

USE_BUILDLINK2=		YES
APACHE_MODULE=		YES

.include "../../www/php4/Makefile.php"

# Ensure we export symbols in the linked shared object.
.if ${OPSYS} != "SunOS"
LDFLAGS+=		-Wl,--export-dynamic
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so	\
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../www/apache/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
