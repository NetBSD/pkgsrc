# $NetBSD: Makefile,v 1.12 2003/08/23 14:22:43 grant Exp $
#

PKGNAME=		ap-php-${BASE_VERS}
PKGREVISION=		1
COMMENT=		Apache 1.x module for PHP3

USE_BUILDLINK2=		yes

.include "../../www/php3/Makefile.common"

DEPENDS+=		php>=${BASE_VERS}:../../www/php3
DEPENDS+=		${BUILDLINK_DEPENDS.apache}:../../www/apache

CPPFLAGS+=		-DPHP_INTERNAL_FUNCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/libphp3.so ${PREFIX}/lib/httpd/mod_php3.so

.include "../../www/apache/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
