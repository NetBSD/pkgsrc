# $NetBSD: Makefile,v 1.23 2012/10/28 06:30:03 asau Exp $

DISTNAME=		mod_dav-1.0.3-1.3.6
PKGNAME=		ap13-dav-1.0.3
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/mod_dav/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.webdav.org/mod_dav/
COMMENT=		Apache WebDAV module

CONFLICTS=		ap-dav-[0-9]*

APACHE_MODULE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat}

AP_MODULE_DIR=		${PREFIX}/lib/httpd
DOCDIR=			${PREFIX}/share/doc/mod_dav
HTMLDIR=		${PREFIX}/share/doc/html/mod_dav

INSTALLATION_DIRS=	${AP_MODULE_DIR} ${DOCDIR} ${HTMLDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libdav.so ${DESTDIR}${AP_MODULE_DIR}/mod_dav.so
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.html ${DESTDIR}${HTMLDIR}

.include "../../textproc/expat/buildlink3.mk"
.include "../../www/apache/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
