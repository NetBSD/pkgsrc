# $NetBSD: Makefile,v 1.3 2002/02/28 18:28:14 jlam Exp $

DISTNAME=		mod_dav-1.0.2-1.3.6
PKGNAME=		ap-dav-1.0.2
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/mod_dav/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.webdav.org/mod_dav/
COMMENT=		Apache WebDAV module

# Ugly mess that says apache>=1.3.9 and apache<=2.0.
BUILDLINK_DEPENDS.apache=	{apache-1.3.9*,apache-1.3.[1-9][0-9]*,apache6-1.3.9*,apache6-1.3.[1-9][0-9]*}

DEPENDS+=		${BUILDLINK_DEPENDS.apache}:../../www/apache

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

AP_MODULE_DIR=		${PREFIX}/lib/httpd
DOCDIR=			${PREFIX}/share/doc/mod_dav
HTMLDIR=		${PREFIX}/share/doc/html/mod_dav

do-install:
	${INSTALL_DATA} ${WRKSRC}/libdav.so ${AP_MODULE_DIR}/mod_dav.so
	${INSTALL_DATA_DIR} ${DOCDIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.html ${HTMLDIR}

.include "../../textproc/expat/buildlink.mk"
.include "../../www/apache/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
