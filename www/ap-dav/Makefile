# $NetBSD: Makefile,v 1.10 2004/04/24 22:46:12 jlam Exp $

DISTNAME=		mod_dav-1.0.3-1.3.6
PKGNAME=		ap-dav-1.0.3
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/mod_dav/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.webdav.org/mod_dav/
COMMENT=		Apache WebDAV module

# Ugly mess that says apache>=1.3.9 and apache<2.0.
BUILDLINK_DEPENDS.apache=	{apache-1.3.9*,apache-1.3.[1-9][0-9]*,apache6-1.3.9*,apache6-1.3.[1-9][0-9]*}

USE_BUILDLINK2=		YES
APACHE_MODULE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat}

AP_MODULE_DIR=		${PREFIX}/lib/httpd
DOCDIR=			${PREFIX}/share/doc/mod_dav
HTMLDIR=		${PREFIX}/share/doc/html/mod_dav

do-install:
	${INSTALL_DATA} ${WRKSRC}/libdav.so ${AP_MODULE_DIR}/mod_dav.so
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.html ${HTMLDIR}

.include "../../textproc/expat/buildlink2.mk"
.include "../../www/apache/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
