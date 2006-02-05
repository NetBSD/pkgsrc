# $NetBSD: Makefile,v 1.8 2006/02/05 23:11:15 joerg Exp $
#

DISTNAME=	skippy-0.5.0
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	http://thegraveyard.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://thegraveyard.org/skippy.php
COMMENT=	Fullscreen task switcher for X11

USE_TOOLS+=		pkg-config
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/skippyrc-default ${EGDIR}/skippyrc

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
