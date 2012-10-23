# $NetBSD: Makefile,v 1.21 2012/10/23 10:24:11 wiz Exp $
#

DISTNAME=	asclock-xlib-2.0.11
PKGNAME=	asclock-xlib-2.0b11
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_LOCAL}	# www.asclock.org is no more

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Dockable clock and calendar with themes for X11

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

WRKSRC=		${WRKDIR}/asclock-xlib
USE_IMAKE=	YES

PLIST_SRC=	${PKGDIR}/PLIST \
		${PKGDIR}/PLIST.themes

INSTALLATION_DIRS=	share/doc/asclock-xlib share/asclock-xlib

pre-configure:
	cd ${WRKSRC}; ${LN} -sf themes/classic default_theme

pre-install:
	${RM} -f ${WRKSRC}/themes/Freeamp/Makefile*

post-install:
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING README.THEMES \
		${DESTDIR}${PREFIX}/share/doc/asclock-xlib
	${CP} -R ${WRKSRC}/themes/* ${DESTDIR}${PREFIX}/share/asclock-xlib
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/asclock-xlib

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
