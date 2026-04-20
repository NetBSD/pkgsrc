# $NetBSD: Makefile,v 1.4 2026/04/20 15:48:19 vins Exp $

DISTNAME=	xfind-src
PKGNAME=	xfind-1.0.4
CATEGORIES=	x11
MASTER_SITES=	https://fastestcode.org/dl/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://fastestcode.org/xfile.html
COMMENT=	Graphical file search utility for X11
LICENSE=	isc

WRKSRC=		${WRKDIR}/${PKGBASE}

MAKE_FILE=		make.local
USE_BSD_MAKEFILE=	yes

PIXMAPDIR=		share/pixmaps
APPLRESDIR=		lib/X11/app-defaults

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/applications
INSTALLATION_DIRS+=	${PIXMAPDIR} ${APPLRESDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/xfind.xpm	  \
		${DESTDIR}${PREFIX}/${PIXMAPDIR}/xfind_48x48.xpm
	${INSTALL_DATA} ${WRKSRC}/XFind.ad	  \
		${DESTDIR}${PREFIX}/${APPLRESDIR}/XFind
	${INSTALL_DATA} ${FILESDIR}/xfind.desktop \
		${DESTDIR}${PREFIX}/share/applications

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
