# $NetBSD: Makefile,v 1.1.1.1 2000/02/06 00:41:46 wiz Exp $

DISTNAME=	wmCalClock-1.25
CATEGORIES=	x11
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml

DEPENDS=	xpm-3.4k:../../graphics/xpm/

WRKSRC=		${WRKDIR}/${DISTNAME}/Src

USE_X11BASE=	yes
USE_GMAKE=	yes

do-install:
	${INSTALL_MAN} ${WRKSRC}/wmCalClock.1 ${PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/wmCalClock ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
