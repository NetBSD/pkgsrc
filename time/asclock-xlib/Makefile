# $NetBSD: Makefile,v 1.3 2001/02/25 04:18:19 hubertf Exp $
#

DISTNAME=	asclock-xlib-2.0.11
PKGNAME=	asclock-xlib-2.0b11
WRKSRC=		${WRKDIR}/asclock-xlib
CATEGORIES=	x11 time
MASTER_SITES=	http://www.asclock.org/tar/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.asclock.org/
COMMENT=	dockable clock and calendar with themes for X11

USE_IMAKE=	YES
USE_XPM=	YES

PLIST_SRC=	${PKGDIR}/PLIST \
		${PKGDIR}/PLIST.themes

pre-configure:
	cd ${WRKSRC}; ${LN} -sf themes/classic default_theme

pre-install:
	${RM} -f ${WRKSRC}/themes/Freeamp/Makefile*

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/asclock-xlib
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING README.THEMES \
		${PREFIX}/share/doc/asclock-xlib
	${INSTALL_DATA_DIR} ${PREFIX}/share/asclock-xlib
	${CP} -R ${WRKSRC}/themes/* ${PREFIX}/share/asclock-xlib
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/asclock-xlib

.include "../../mk/bsd.pkg.mk"
