# $NetBSD: Makefile,v 1.7 2001/08/22 17:38:59 jlam Exp $
#

DISTNAME=	asclock-xlib-2.0.11
PKGNAME=	asclock-xlib-2.0b11
WRKSRC=		${WRKDIR}/asclock-xlib
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_LOCAL}	# www.asclock.org is no more

MAINTAINER=	jlam@netbsd.org
COMMENT=	dockable clock and calendar with themes for X11

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

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

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
