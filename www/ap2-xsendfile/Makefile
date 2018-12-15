# $NetBSD: Makefile,v 1.5 2018/12/15 21:12:24 wiz Exp $

DISTNAME=		mod_xsendfile-0.12
PKGNAME=		${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=		www
MASTER_SITES=		https://tn123.org/mod_xsendfile/

MAINTAINER=		fhajny@NetBSD.org
HOMEPAGE=		https://tn123.org/mod_xsendfile/
COMMENT=		Apache 2 module that processes X-SENDFILE headers
LICENSE=		apache-2.0

APACHE_MODULE=		YES
APACHE_MODULE_NAME=	${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRC=	${DISTNAME:C|-.*||}.c
APACHE_MODULE_LA=	${DISTNAME:C|-.*||}.la

do-build:
	cd ${WRKSRC} && ${APXS} ${CPPFLAGS} ${LDFLAGS} -c -o ${APACHE_MODULE_NAME} ${APACHE_MODULE_SRC}

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib/httpd
	cd ${WRKSRC} && ${APXS} -i -S LIBEXECDIR=${DESTDIR}${PREFIX}/lib/httpd ${APACHE_MODULE_LA}

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
