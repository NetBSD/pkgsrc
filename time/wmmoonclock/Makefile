# $NetBSD: Makefile,v 1.3 2002/10/21 13:05:01 wiz Exp $
#

DISTNAME=	wmMoonClock-1.27
CATEGORIES=	x11 time
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	Shows lunar ephemeris to fairly high accuracy

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES
WRKSRC=         ${WRKDIR}/${DISTNAME}/Src

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
