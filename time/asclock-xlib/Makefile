# $NetBSD: Makefile,v 1.11 2004/01/20 12:27:16 agc Exp $
#

DISTNAME=	asclock-xlib-2.0.11
PKGNAME=	asclock-xlib-2.0b11
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_LOCAL}	# www.asclock.org is no more

MAINTAINER=	jlam@NetBSD.org
COMMENT=	Dockable clock and calendar with themes for X11

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

WRKSRC=		${WRKDIR}/asclock-xlib
USE_BUILDLINK2=	YES
USE_IMAKE=	YES
USE_X11BASE=	YES

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

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
