# $NetBSD: Makefile,v 1.14 2001/08/23 04:19:58 jlam Exp $
#

DISTNAME=		Xaw-XPM-1.1
PKGNAME=		Xaw-Xpm-1.1
WRKSRC=			${WRKDIR}/XawXpm
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=libs/X/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.zip.com.au/~bb/XawXpm/
COMMENT=		Enhanced 3-D widgets based on the Athena Widget set and Xaw3d

CONFLICTS=		Xaw3d-*

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

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
