# $NetBSD: Makefile,v 1.3 2000/08/23 23:14:37 tron Exp $
#

DISTNAME=	xpenguins-1.2
CATEGORIES=	games x11
MASTER_SITES=	http://www.met.rdg.ac.uk/~swrhgnrj/xpenguins/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.met.rdg.ac.uk/~swrhgnrj/xpenguins/

USE_XPM=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpenguins	 ${PREFIX}/bin
	${INSTALL_MAN}     ${WRKSRC}/xpenguins.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
