# $NetBSD: Makefile,v 1.32 2016/01/06 21:42:27 leot Exp $
#

DISTNAME=		Xaw-XPM-1.1
PKGNAME=		Xaw-Xpm-1.1
PKGREVISION=		4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=libs/X/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.zip.com.au/~bb/XawXpm/
COMMENT=		Enhanced 3-D widgets based on the Athena Widget set and Xaw3d

CONFLICTS=		libXaw3d-[0-9]*

WRKSRC=			${WRKDIR}/XawXpm
USE_IMAKE=		YES
PLIST_SRC=		${WRKDIR}/.PLIST_SRC

INSTALLATION_DIRS=	share/doc/Xaw-Xpm share/pixmaps

post-install:
	${INSTALL_DATA} ${WRKSRC}/README-XPM ${DESTDIR}${PREFIX}/share/doc/Xaw-Xpm
	${INSTALL_DATA} ${WRKSRC}/defaults-XawXpm ${DESTDIR}${PREFIX}/share/doc/Xaw-Xpm
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.xpm ${DESTDIR}${PREFIX}/share/pixmaps
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	cd ${DESTDIR}${PREFIX} && ${LS} lib/libXaw3d* >> ${PLIST_SRC}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
