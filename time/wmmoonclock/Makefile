# $NetBSD: Makefile,v 1.5 2003/03/29 12:42:44 jmmv Exp $
#

DISTNAME=	wmMoonClock-1.27
WRKSRC=         ${WRKDIR}/${DISTNAME}/Src
CATEGORIES=	x11 time
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	Shows lunar ephemeris to fairly high accuracy

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
