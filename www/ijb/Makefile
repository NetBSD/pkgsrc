# $NetBSD: Makefile,v 1.4 2003/07/17 22:55:37 grant Exp $
#

DISTNAME=	ijb20
PKGNAME=	ijb-2.0.2
CATEGORIES=	www
MASTER_SITES=	http://www.junkbuster.com/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.junkbuster.com/
COMMENT=	The Internet Junkbuster Proxy blocks unwanted banner ads and cookies

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/junkbuster ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/junkbuster.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/junkbuster
	${INSTALL_DATA} ${WRKSRC}/junkbstr.ini ${PREFIX}/share/examples/junkbuster/junkbuster.ini

.include "../../mk/bsd.pkg.mk"
