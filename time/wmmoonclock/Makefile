# $NetBSD: Makefile,v 1.4 2002/10/27 13:40:30 bouyer Exp $
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

MAKE_FLAGS+=    EXTRA_LOCAL_LIBS=${EXTRA_LOCAL_LIBS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
EXTRA_LOCAL_LIBS=       -lsocket
.endif

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
