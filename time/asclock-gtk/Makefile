# $NetBSD: Makefile,v 1.8 2001/10/23 13:15:03 jlam Exp $
#

DISTNAME=	asclock-gtk-2.1.10beta
PKGNAME=	asclock-gtk-2.1.10
WRKSRC=		${WRKDIR}/asclock-gtk
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_LOCAL}	# www.asclock.org is no more

MAINTAINER=	jlam@netbsd.org
COMMENT=	dockable clock and calendar with themes for GTK+

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

USE_BUILDLINK_ONLY=	# defined
USE_CONFIG_WRAPPER=	# defined
USE_X11BASE=		# defined

PLIST_SRC=	${PKGDIR}/PLIST \
		${PKGDIR}/PLIST.themes

ALL_TARGET=	asclock
MAKE_ENV+=	CONFIG_PATH="${BUILDLINK_DIR}/bin/"	# for gtk-config

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

.include "../../mk/x11.buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
