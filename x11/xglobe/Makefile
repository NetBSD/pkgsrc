# $NetBSD: Makefile,v 1.17 2002/07/10 17:15:18 mycroft Exp $
#

DISTNAME=	xglobe-0.5
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

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.cs.unc.edu/~scheuerm/xglobe/
COMMENT=	Displays the earth as seen from space, similar to xearth

DEPENDS+=	qt1-1.44:../../x11/qt1

DIST_SUBDIR=	xglobe
MAPS=		LE.400.gif Brill.400.gif mggd.gif
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_X11BASE=	YES
USE_GMAKE=	YES
EVAL_PREFIX+=	QT1DIR=qt1
MAKE_ENV+=	QTDIR=${QT1DIR}/qt1

post-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/lib/xglobe
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/mggd.gif      ${X11PREFIX}/lib/xglobe/mggd.gif
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/LE.400.gif    ${X11PREFIX}/lib/xglobe/daymap.gif
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Brill.400.gif ${X11PREFIX}/lib/xglobe/nightmap.gif
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/doc/xglobe
	${INSTALL_DATA} ${WRKSRC}/README	 ${X11PREFIX}/share/doc/xglobe
	${INSTALL_DATA} ${WRKSRC}/README.maps	 ${X11PREFIX}/share/doc/xglobe
	${INSTALL_DATA} ${WRKSRC}/getcloudmap.sh ${X11PREFIX}/bin/xglobe-getcloudmap.sh

.include "../../mk/bsd.pkg.mk"
