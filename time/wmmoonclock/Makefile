# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:45 tv Exp $
#

DISTNAME=	wmMoonClock-1.27
CATEGORIES=	x11 time
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	Shows lunar ephemeris to fairly high accuracy

WRKSRC=         ${WRKDIR}/${DISTNAME}/Src
USE_GNU_TOOLS+=	make
USE_X11BASE=	YES

MAKE_FLAGS+=    EXTRA_LOCAL_LIBS=${EXTRA_LOCAL_LIBS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
EXTRA_LOCAL_LIBS=       -lsocket
.endif

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
