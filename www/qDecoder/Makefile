# $NetBSD: Makefile,v 1.2 2003/06/02 01:15:59 jschauma Exp $

DISTNAME=	qDecoder-7.0.1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.qDecoder.org/pub/qDecoder/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.qDecoder.org/
COMMENT=	Web Application Interface for C/C++ (CGI Library)

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/qDecoder
	cd ${WRKSRC}; ${INSTALL_DATA} AUTHORS CHANGES COPYING	\
		DISCLAIMER README REFERENCE qDecoder.jpg 	\
		${PREFIX}/share/doc/qDecoder
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/qDecoder
	cd ${WRKSRC}/examples; ${INSTALL_DATA} *.c *.conf s*.in	\
		*.html ${PREFIX}/share/examples/qDecoder

.include "../../mk/bsd.pkg.mk"
