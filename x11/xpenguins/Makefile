# $NetBSD: Makefile,v 1.5 2001/02/17 17:07:21 wiz Exp $
#

DISTNAME=	xpenguins-1.2
CATEGORIES=	games x11
MASTER_SITES=	http://xpenguins.seul.org/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://xpenguins.seul.org/
COMMENT=	Little penguins walking along the tops of your windows

USE_XPM=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpenguins	 ${PREFIX}/bin
	${INSTALL_MAN}     ${WRKSRC}/xpenguins.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
