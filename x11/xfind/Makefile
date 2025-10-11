# $NetBSD: Makefile,v 1.2 2025/10/11 16:48:48 vins Exp $

DISTNAME=	xfind-src
VERSION=	1.0.3
PKGNAME=	${DISTNAME:S,-src,,}-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	https://fastestcode.org/dl/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://fastestcode.org/xfile.html
COMMENT=	Graphical file search utility for X11
LICENSE=	isc

WRKSRC=		${WRKDIR}/${PKGBASE}

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	pre-configure
SUBST_FILES.pkgsrc=	make.local
SUBST_VARS.pkgsrc+=	PREFIX PKGMANDIR
SUBST_MESSAGE.pkgsrc=	Replacing pkgsrc placeholders

MAKE_FILE=	make.local

INSTALLATION_DIRS+=	share/applications

post-install:
	${INSTALL_DATA} ${FILESDIR}/xfind.desktop	\
		${DESTDIR}${PREFIX}/share/applications

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
