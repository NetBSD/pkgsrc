# $NetBSD: Makefile,v 1.3 1999/10/28 19:06:21 jlam Exp $
#

DISTNAME=	asclock-gtk-2.1.10beta
PKGNAME=	asclock-gtk-2.1.10
WRKSRC=		${WRKDIR}/asclock-gtk
CATEGORIES=	x11
MASTER_SITES=	http://www.asclock.org/tar/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.asclock.org/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk

USE_X11BASE=	yes

PLIST_SRC=	${PKGDIR}/PLIST \
		${PKGDIR}/PLIST.themes

ALL_TARGET=	asclock
MAKE_ENV+=	CONFIG_PATH="${X11BASE}/bin/"	# for gtk-config

pre-configure:
	cd ${WRKSRC}; ${LN} -sf themes/classic default_theme

pre-install:
	${RM} -f ${WRKSRC}/themes/Freeamp/Makefile*
	${RM} -rf ${WRKSRC}/themes/themes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asclock ${PREFIX}/bin/asclock-gtk
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/asclock-gtk
	${INSTALL_DATA} ${WRKSRC}/README.THEMES ${PREFIX}/share/doc/asclock-gtk
	${MKDIR} ${PREFIX}/share/asclock-gtk
	${CP} -R ${WRKSRC}/themes/* ${PREFIX}/share/asclock-gtk
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/asclock-gtk

.include "../../mk/bsd.pkg.mk"
