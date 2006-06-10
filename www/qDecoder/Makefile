# $NetBSD: Makefile,v 1.5 2006/06/10 19:43:24 minskim Exp $

DISTNAME=	qDecoder-7.0.1
CATEGORIES=	www
PKGREVISION=	1
MASTER_SITES=	ftp://ftp.qDecoder.org/pub/qDecoder/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qDecoder.org/
COMMENT=	Web Application Interface for C/C++ (CGI Library)

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/qDecoder
	cd ${WRKSRC}; ${INSTALL_DATA} AUTHORS CHANGES COPYING	\
		DISCLAIMER README REFERENCE qDecoder.jpg 	\
		${PREFIX}/share/doc/qDecoder
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/qDecoder
	cd ${WRKSRC}/examples; ${INSTALL_DATA} *.c *.conf s*.in	\
		*.html ${PREFIX}/share/examples/qDecoder

.include "../../mk/bsd.pkg.mk"
