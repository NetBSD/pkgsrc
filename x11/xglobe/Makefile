# $NetBSD: Makefile,v 1.21 2004/10/03 00:18:40 tv Exp $
#

DISTNAME=	xglobe-0.5
PKGREVISION=	2
CATEGORIES=	x11
#
# The original MASTER_SITE for the program responds "200 OK"
# and produces a page explaining how the user "uddn" no longer
# has web pages on their system.
#
MASTER_SITES=	http://www.cs.unc.edu/~scheuerm/xglobe/ \
		http://livingearth.com/LE/images/ \
		http://www.ngdc.noaa.gov/mgg/image/
DISTFILES+=	${MAPS} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.cs.unc.edu/~scheuerm/xglobe/
COMMENT=	Displays the earth as seen from space, similar to xearth

DIST_SUBDIR=	xglobe
MAPS=		LE.400.gif Brill.400.gif mggd.gif
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_X11BASE=	YES
USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes

post-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/lib/xglobe
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/mggd.gif      ${X11PREFIX}/lib/xglobe/mggd.gif
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/LE.400.gif    ${X11PREFIX}/lib/xglobe/daymap.gif
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Brill.400.gif ${X11PREFIX}/lib/xglobe/nightmap.gif
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/doc/xglobe
	${INSTALL_DATA} ${WRKSRC}/README	 ${X11PREFIX}/share/doc/xglobe
	${INSTALL_DATA} ${WRKSRC}/README.maps	 ${X11PREFIX}/share/doc/xglobe
	${INSTALL_DATA} ${WRKSRC}/getcloudmap.sh ${X11PREFIX}/bin/xglobe-getcloudmap.sh

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
