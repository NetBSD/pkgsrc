# $NetBSD: Makefile,v 1.7 2004/01/20 12:27:16 agc Exp $
#

DISTNAME=	wmMoonClock-1.27
CATEGORIES=	x11 time
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	Shows lunar ephemeris to fairly high accuracy

WRKSRC=         ${WRKDIR}/${DISTNAME}/Src
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES

MAKE_FLAGS+=    EXTRA_LOCAL_LIBS=${EXTRA_LOCAL_LIBS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
EXTRA_LOCAL_LIBS=       -lsocket
.endif

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
