# $NetBSD: Makefile,v 1.2 1999/01/06 14:02:33 frueauf Exp $
#

DISTNAME=	xglobe-0.1
CATEGORIES=	x11
MASTER_SITES=	http://www.uni-karlsruhe.de/~uddn/xglobe/ \
		http://livingearth.com/LE/images/ \
		http://www.ngdc.noaa.gov/mgg/image/
DISTFILES+=	${MAPS} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.uni-karlsruhe.de/~uddn/xglobe/

DEPENDS+=	qt-1.42:../../x11/qt

DIST_SUBDIR=	xglobe
MAPS=		LE.400.gif Brill.400.gif mggd.gif
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_X11=	YES
USE_GMAKE=	YES
MAKE_ENV+=	QTDIR=${X11BASE}

post-install:
	${INSTALL_DATA} ${DISTDIR}/mggd.gif      ${X11BASE}/lib/X11/xglobe/map.bmp
	${INSTALL_DATA} ${DISTDIR}/LE.400.gif    ${X11BASE}/lib/X11/xglobe/daymap.gif
	${INSTALL_DATA} ${DISTDIR}/Brill.400.gif ${X11BASE}/lib/X11/xglobe/nightmap.gif

.include "../../mk/bsd.pkg.mk"
