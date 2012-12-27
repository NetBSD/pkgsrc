# $NetBSD: Makefile,v 1.12 2012/12/27 20:12:26 ryoon Exp $
#

DISTNAME=	qDecoder-9.0.1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.qDecoder.org/pub/qDecoder/

MAINTAINER=	jypak@users.sourceforge.net
HOMEPAGE=	http://www.qDecoder.org/
COMMENT=	Web Application Interface for C/C++ (CGI Library)

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
INSTALLATION_DIRS=	include lib share/doc/qDecoder share/doc/qDecoder/html \
			share/examples/qDecoder share/examples/qDecoder/qDecoder-upload

post-install:
	cd ${WRKSRC}; ${INSTALL_DATA} AUTHORS CHANGES COPYING \
		qDecoder.jpg ${DESTDIR}${PREFIX}/share/doc/qDecoder
	cd ${WRKSRC}/src; ${INSTALL_DATA} qDecoder.h ${DESTDIR}${PREFIX}/include
	cd ${WRKSRC}/doc/html; ${INSTALL_DATA} * ${DESTDIR}${PREFIX}/share/doc/qDecoder/html
	cd ${WRKSRC}/examples; ${INSTALL_DATA} *.c *.conf s*.in \
		*.html ${DESTDIR}${PREFIX}/share/examples/qDecoder
	cd ${WRKSRC}/examples/qDecoder-upload; ${INSTALL_DATA} *.html *.js \
		${DESTDIR}${PREFIX}/share/examples/qDecoder/qDecoder-upload

.include "../../mk/bsd.pkg.mk"
