# $NetBSD: Makefile,v 1.37 2026/11/25 17:01:23 wiz Exp $

PKGNAME=		ap24-${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=		27
COMMENT=		Passenger module for Apache 2.x

BUILDLINK_DEPMETHOD.curl=	build

DEPENDS+=		${RUBY_PKGPREFIX}-${DISTNAME}{,nb*}:../../www/passenger

.include "../../www/passenger/Makefile.common"

APACHE_MODULE=		yes

# Get rid of these bits from www/apache24 as they break build on SunOS
BUILDLINK_TRANSFORM+=	rm:-D_XOPEN_SOURCE
BUILDLINK_TRANSFORM+=	rm:-D_XOPEN_SOURCE_EXTENDED=1

INSTALLATION_DIRS+=	lib/httpd

do-build:
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} ${RAKE} -j ${_MAKE_JOBS_N} apache2

do-install:
	${INSTALL_LIB} ${WRKSRC}/buildout/apache2/mod_passenger.so \
	  ${DESTDIR}${PREFIX}/lib/httpd/mod_passenger.so

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
