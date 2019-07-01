# $NetBSD: Makefile,v 1.8 2019/07/01 04:08:51 ryoon Exp $

PKGNAME=		${APACHE_PKG_PREFIX}-${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=		1
COMMENT=		Passenger module for Apache 2.x

BUILDLINK_DEPMETHOD.curl=	build

DEPENDS+=		${RUBY_PKGPREFIX}-${DISTNAME}{,nb*}:../../www/passenger

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
