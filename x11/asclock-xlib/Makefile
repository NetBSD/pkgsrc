# $NetBSD: Makefile,v 1.1.1.1 1999/10/07 17:26:15 jlam Exp $
#

DISTNAME=	asclock-xlib-2.0.11
PKGNAME=	asclock-xlib-2.0b11
WRKSRC=		${WRKDIR}/asclock-xlib
CATEGORIES=	x11
MASTER_SITES=	http://www.asclock.org/tar/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.asclock.org/

DEPENDS+=	xpm-3.4k:../../graphics/xpm

CONFLICTS=	asclock-* asclock-gtk-*

USE_IMAKE=	yes

PLIST_SRC=	${PKGDIR}/PLIST \
		${PKGDIR}/PLIST.languages \
		${PKGDIR}/PLIST.themes

pre-configure:
	cd ${WRKSRC}; ${LN} -sf themes/classic default_theme

pre-install:
	${RM} -f ${WRKSRC}/themes/Freeamp/Makefile*

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/asclock
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING README.THEMES \
		${PREFIX}/share/doc/asclock
	${MKDIR} ${PREFIX}/share/asclock
	${CP} -R ${WRKSRC}/themes/* ${PREFIX}/share/asclock
	${MKDIR} ${PREFIX}/share/examples/asclock
	${CP} -R ${WRKSRC}/languages/* ${PREFIX}/share/examples/asclock
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/share/asclock ${PREFIX}/share/examples/asclock

.include "../../mk/bsd.pkg.mk"
