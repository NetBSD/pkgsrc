# $NetBSD: Makefile,v 1.13 2014/02/12 23:18:43 tron Exp $

DISTNAME=	mod_auth_radius
PKGNAME=	${APACHE_PKG_PREFIX}-auth-radius-1.5.7
PKGREVISION=	5
CATEGORIES=	www databases
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freeradius.org/mod_auth_radius/
COMMENT=	Module to allow apache2 authentication against a RADIUS server

WRKSRC=			${WRKDIR}/${DISTNAME}-1.5.7
EXTRACT_SUFX=		.tar
NO_CONFIGURE=		YES
APACHE_MODULE=		YES
APACHE_MODULE_NAME=	mod_auth_radius.la
APACHE_MODULE_SRC=	mod_auth_radius.c
USE_LIBTOOL=		YES

PKG_APACHE_ACCEPTED=	apache2 apache22
.include "../../mk/apache.mk"
.include "../../www/apache/module.mk"
BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.47

.include "../../security/openssl/buildlink3.mk"

post-extract:
	${MV} ${WRKSRC}/mod_auth_radius.c ${WRKSRC}/mod_auth_radius-1.0.c
	${MV} ${WRKSRC}/mod_auth_radius-2.0.c ${WRKSRC}/mod_auth_radius.c

INSTALLATION_DIRS+=	share/doc/mod_auth_radius share/examples/mod_auth_radius

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mod_auth_radius
	${INSTALL_DATA} ${WRKSRC}/index.html ${DESTDIR}${PREFIX}/share/doc/mod_auth_radius

	${INSTALL_DATA} ${WRKSRC}/htaccess \
	    ${DESTDIR}${PREFIX}/share/examples/mod_auth_radius
	${INSTALL_DATA} ${WRKSRC}/httpd.conf \
	    ${DESTDIR}${PREFIX}/share/examples/mod_auth_radius

.include "../../mk/bsd.pkg.mk"
