# $NetBSD: Makefile,v 1.4 2000/12/12 13:56:53 wiz Exp $
#

DISTNAME=	xpenguins-1.2
CATEGORIES=	games x11
MASTER_SITES=	http://xpenguins.seul.org/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://xpenguins.seul.org/

USE_XPM=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpenguins	 ${PREFIX}/bin
	${INSTALL_MAN}     ${WRKSRC}/xpenguins.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
