# $NetBSD: Makefile,v 1.1.1.1 2000/02/09 17:44:50 abs Exp $
#

DISTNAME=	ijb20
PKGNAME=	ijb-2.0.2
CATEGORIES=	www
MASTER_SITES=	http://www.junkbuster.com/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.junkbuster.com/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/junkbuster ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/junkbuster.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/examples/junkbuster
	${INSTALL_DATA} ${WRKSRC}/junkbstr.ini ${PREFIX}/share/examples/junkbuster/junkbuster.ini

.include "../../mk/bsd.pkg.mk"
