# $NetBSD: Makefile,v 1.1 2018/01/30 12:06:49 fhajny Exp $

PKGNAME=		${APACHE_PKG_PREFIX}-${RUBY_PKGPREFIX}-${DISTNAME}
COMMENT=		Passenger module for Apache 2.x

BUILDLINK_DEPMETHOD.curl=	build

DEPENDS+=		${RUBY_PKGPREFIX}-${DISTNAME}:../../www/passenger

.include "../../www/passenger/Makefile.common"

APACHE_MODULE=		yes
USE_APR=		yes

# Get rid of these bits from www/apache24 as they break build on SunOS
BUILDLINK_TRANSFORM+=	rm:-D_XOPEN_SOURCE
BUILDLINK_TRANSFORM+=	rm:-D_XOPEN_SOURCE_EXTENDED=1

INSTALLATION_DIRS+=	lib/httpd

do-build:
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} ${RAKE} apache2

do-install:
	${INSTALL_LIB} ${WRKSRC}/buildout/apache2/mod_passenger.so \
	  ${DESTDIR}${PREFIX}/lib/httpd/mod_passenger.so

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
