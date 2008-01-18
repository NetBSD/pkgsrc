# $NetBSD: Makefile,v 1.7 2008/01/18 05:09:47 tnn Exp $

DISTNAME=	mod_auth_radius
PKGNAME=	${APACHE_PKG_PREFIX}-auth-radius-1.5.7
PKGREVISION=	2
CATEGORIES=	www databases
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.freeradius.org/mod_auth_radius/
COMMENT=	Module to allow apache2 authentication against a RADIUS server

WRKSRC=			${WRKDIR}/${DISTNAME}-1.5.7
EXTRACT_SUFX=		.tar
NO_CONFIGURE=		YES
APACHE_MODULE=		YES
APACHE_MODULE_NAME=	mod_auth_radius
USE_LIBTOOL=		YES

PKG_APACHE_ACCEPTED=	apache2 apache22
.include "../../mk/apache.mk"
BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.47

.include "../../security/openssl/buildlink3.mk"

post-extract:
	${MV} ${WRKSRC}/mod_auth_radius.c ${WRKSRC}/mod_auth_radius-1.0.c
	${MV} ${WRKSRC}/mod_auth_radius-2.0.c ${WRKSRC}/mod_auth_radius.c

do-build:
	cd ${WRKSRC} && \
		${APXS} -c -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_NAME}.c

do-install:
	cd ${WRKSRC} && ${APXS} -i -n ${APACHE_MODULE_NAME} \
		${APACHE_MODULE_NAME}.la

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_radius
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mod_auth_radius
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/doc/mod_auth_radius

	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mod_auth_radius
	${INSTALL_DATA} ${WRKSRC}/htaccess \
		${PREFIX}/share/examples/mod_auth_radius
	${INSTALL_DATA} ${WRKSRC}/httpd.conf \
		${PREFIX}/share/examples/mod_auth_radius

.include "../../mk/bsd.pkg.mk"
