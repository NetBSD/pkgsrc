# $NetBSD: Makefile,v 1.18 2004/04/24 22:46:12 jlam Exp $
#

DISTNAME=	asclock-gtk-2.1.10beta
PKGNAME=	asclock-gtk-2.1.10
PKGREVISION=	2
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_LOCAL}	# www.asclock.org is no more

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Dockable clock and calendar with themes for GTK+

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

WRKSRC=		${WRKDIR}/asclock-gtk
USE_BUILDLINK3=	yes
USE_X11BASE=	# defined

PLIST_SRC=	${PKGDIR}/PLIST \
		${PKGDIR}/PLIST.themes

ALL_TARGET=	asclock

pre-configure:
	cd ${WRKSRC}; ${LN} -sf themes/classic default_theme

pre-install:
	${RM} -f ${WRKSRC}/themes/Freeamp/Makefile*
	${RM} -rf ${WRKSRC}/themes/themes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asclock ${PREFIX}/bin/asclock-gtk
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/asclock-gtk
	${INSTALL_DATA} ${WRKSRC}/README.THEMES ${PREFIX}/share/doc/asclock-gtk
	${INSTALL_DATA_DIR} ${PREFIX}/share/asclock-gtk
	${CP} -R ${WRKSRC}/themes/* ${PREFIX}/share/asclock-gtk
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/asclock-gtk

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
