# $NetBSD: Makefile,v 1.2 2000/08/23 23:14:37 tron Exp $

DISTNAME=	wmCalClock-1.25
CATEGORIES=	x11
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
