# $NetBSD: Makefile,v 1.20 2002/02/28 06:14:46 jlam Exp $

PKGNAME=		ap-php-${PHP_BASE_VERS}
PKGREVISION=		# empty
COMMENT=		Apache module for PHP4

DEPENDS+=		php>=${PHP_BASE_VERS}:../../www/php4
DEPENDS+=		apache{,6}>=1.3:../../www/apache

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.php"

# Ensure we export symbols in the linked shared object.
.if ${OPSYS} != "SunOS"
LDFLAGS+=		-Wl,--export-dynamic
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so	\
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../www/apache/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
