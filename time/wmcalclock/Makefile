# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 23:32:21 wiz Exp $
#

DISTNAME=	wmCalClock-1.25
CATEGORIES=	x11 time
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml

USE_X11BASE=	YES
USE_XPM=	YES
USE_GMAKE=	YES

WRKSRC=		${WRKDIR}/${DISTNAME}/Src

do-install:
	${INSTALL_MAN} ${WRKSRC}/wmCalClock.1 ${PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/wmCalClock ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
