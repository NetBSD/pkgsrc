# $NetBSD: Makefile,v 1.6 2007/03/28 13:30:11 joerg Exp $

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
INSTALLATION_DIRS=	include lib share/doc/qDecoder  share/examples/qDecoder

post-install:
	cd ${WRKSRC}; ${INSTALL_DATA} AUTHORS CHANGES COPYING	\
		DISCLAIMER README REFERENCE qDecoder.jpg 	\
		${PREFIX}/share/doc/qDecoder
	cd ${WRKSRC}/examples; ${INSTALL_DATA} *.c *.conf s*.in	\
		*.html ${PREFIX}/share/examples/qDecoder

.include "../../mk/bsd.pkg.mk"
