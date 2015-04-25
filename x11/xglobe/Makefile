# $NetBSD: Makefile,v 1.46 2015/04/25 14:25:25 tnn Exp $
#

DISTNAME=	xglobe-0.5
PKGREVISION=	17
CATEGORIES=	x11
#
# The original MASTER_SITE for the program responds "200 OK"
# and produces a page explaining how the user "uddn" no longer
# has web pages on their system.
#
MASTER_SITES=	http://livingearth.com/LE/images/
DISTFILES+=	${MAPS} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.unc.edu/~scheuerm/xglobe/
COMMENT=	Displays the earth as seen from space, similar to xearth

DIST_SUBDIR=	xglobe
MAPS=		LE.400.gif Brill.400.gif mggd.gif
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_X11BASE=	YES
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

INSTALLATION_DIRS=	lib/xglobe share/doc/xglobe

post-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/mggd.gif      ${DESTDIR}${PREFIX}/lib/xglobe/mggd.gif
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/LE.400.gif    ${DESTDIR}${PREFIX}/lib/xglobe/daymap.gif
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Brill.400.gif ${DESTDIR}${PREFIX}/lib/xglobe/nightmap.gif
	${INSTALL_DATA} ${WRKSRC}/README	 ${DESTDIR}${PREFIX}/share/doc/xglobe
	${INSTALL_DATA} ${WRKSRC}/README.maps	 ${DESTDIR}${PREFIX}/share/doc/xglobe
	${INSTALL_DATA} ${WRKSRC}/getcloudmap.sh ${DESTDIR}${PREFIX}/bin/xglobe-getcloudmap.sh

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
