# $NetBSD: Makefile,v 1.7 2008/11/26 01:23:40 minskim Exp $
#

DISTNAME=	qDecoder-9.0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.qDecoder.org/pub/qDecoder/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qDecoder.org/
COMMENT=	Web Application Interface for C/C++ (CGI Library)

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
INSTALLATION_DIRS=	include lib share/doc/qDecoder share/doc/qDecoder/html \
			share/examples/qDecoder share/examples/qDecoder/qDecoder-upload

post-install:
	cd ${WRKSRC}; ${INSTALL_DATA} AUTHORS CHANGES COPYING \
		qDecoder.jpg ${PREFIX}/share/doc/qDecoder
	cd ${WRKSRC}/doc/html; ${INSTALL_DATA} * ${PREFIX}/share/doc/qDecoder/html
	cd ${WRKSRC}/examples; ${INSTALL_DATA} *.c *.conf s*.in \
		*.html ${PREFIX}/share/examples/qDecoder
	cd ${WRKSRC}/examples/qDecoder-upload; ${INSTALL_DATA} *.html *.js \
		${PREFIX}/share/examples/qDecoder/qDecoder-upload

.include "../../mk/bsd.pkg.mk"
