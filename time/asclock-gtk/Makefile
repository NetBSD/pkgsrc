# $NetBSD: Makefile,v 1.30 2012/10/23 10:24:11 wiz Exp $
#

DISTNAME=	asclock-gtk-2.1.10beta
PKGNAME=	asclock-gtk-2.1.10
PKGREVISION=	5
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_LOCAL}	# www.asclock.org is no more

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Dockable clock and calendar with themes for GTK+

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

WRKSRC=		${WRKDIR}/asclock-gtk
USE_X11BASE=	yes

PLIST_SRC=	${PKGDIR}/PLIST \
		${PKGDIR}/PLIST.themes

BUILD_TARGET=	asclock

INSTALLATION_DIRS=	bin share/asclock-gtk share/doc/asclock-gtk

pre-configure:
	cd ${WRKSRC}; ${LN} -sf themes/classic default_theme

pre-install:
	${RM} -f ${WRKSRC}/themes/Freeamp/Makefile*
	${RM} -rf ${WRKSRC}/themes/themes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asclock ${DESTDIR}${PREFIX}/bin/asclock-gtk
	${INSTALL_DATA} ${WRKSRC}/README.THEMES ${DESTDIR}${PREFIX}/share/doc/asclock-gtk
	${CP} -R ${WRKSRC}/themes/* ${DESTDIR}${PREFIX}/share/asclock-gtk
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/asclock-gtk

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
