# $NetBSD: Makefile,v 1.10 2002/02/28 15:07:16 jlam Exp $
#

PKGNAME=		ap-php-${BASE_VERS}
PKGREVISION=		1
COMMENT=		Apache module for PHP3

USE_BUILDLINK_ONLY=	yes

.include "../../www/php3/Makefile.common"

DEPENDS+=		php>=${BASE_VERS}:../../www/php3
DEPENDS+=		${BUILDLINK_DEPENDS.apache}:../../www/apache

CPPFLAGS+=		-DPHP_INTERNAL_FUNCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/libphp3.so ${PREFIX}/lib/httpd/mod_php3.so

.include "../../www/apache/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
