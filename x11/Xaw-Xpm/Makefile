# $NetBSD: Makefile,v 1.26 2008/01/19 09:16:26 wiz Exp $
#

DISTNAME=		Xaw-XPM-1.1
PKGNAME=		Xaw-Xpm-1.1
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=libs/X/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.zip.com.au/~bb/XawXpm/
COMMENT=		Enhanced 3-D widgets based on the Athena Widget set and Xaw3d

CONFLICTS=		Xaw3d-[0-9]*

WRKSRC=			${WRKDIR}/XawXpm
USE_DIRS+=		xdg-1.1
USE_IMAKE=		YES
PLIST_SRC=		${WRKDIR}/.PLIST_SRC

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Xaw-Xpm
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/README-XPM ${PREFIX}/share/doc/Xaw-Xpm
	${INSTALL_DATA} ${WRKSRC}/defaults-XawXpm ${PREFIX}/share/doc/Xaw-Xpm
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.xpm ${PREFIX}/share/pixmaps
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	cd ${PREFIX} && ${LS} lib/libXaw3d* >> ${PLIST_SRC}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
