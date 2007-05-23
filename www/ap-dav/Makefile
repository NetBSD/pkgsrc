# $NetBSD: Makefile,v 1.21 2007/05/23 12:23:11 ghen Exp $

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

do-install:
	${INSTALL_DATA_DIR} ${AP_MODULE_DIR}
	${INSTALL_DATA} ${WRKSRC}/libdav.so ${AP_MODULE_DIR}/mod_dav.so
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.html ${HTMLDIR}

.include "../../textproc/expat/buildlink3.mk"
.include "../../www/apache/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
