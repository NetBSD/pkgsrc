# $NetBSD: Makefile,v 1.29 2013/07/05 13:29:43 ryoon Exp $
#

DISTNAME=	skippy-0.5.0
PKGREVISION=	17
CATEGORIES=	wm
MASTER_SITES=	http://thegraveyard.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thegraveyard.org/skippy.php
COMMENT=	Fullscreen task switcher for X11

USE_TOOLS+=		pkg-config
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

LDFLAGS.SunOS+=		-lrt

INSTALLATION_DIRS=	share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/skippyrc-default ${DESTDIR}${EGDIR}/skippyrc

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
