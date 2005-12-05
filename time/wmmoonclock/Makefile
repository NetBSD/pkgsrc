# $NetBSD: Makefile,v 1.12 2005/12/05 20:51:09 rillig Exp $
#

DISTNAME=	wmMoonClock-1.27
CATEGORIES=	x11 time
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	Shows lunar ephemeris to fairly high accuracy

WRKSRC=         ${WRKDIR}/${DISTNAME}/Src
USE_TOOLS+=	gmake
USE_X11BASE=	YES

MAKE_FLAGS+=    EXTRA_LOCAL_LIBS=${EXTRA_LOCAL_LIBS:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
EXTRA_LOCAL_LIBS=       -lsocket
.endif

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
