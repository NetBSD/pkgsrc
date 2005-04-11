# $NetBSD: Makefile,v 1.2 2005/04/11 21:47:49 tv Exp $
#

DISTNAME=	skippy-0.5.0
CATEGORIES=	wm
MASTER_SITES=	http://thegraveyard.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://thegraveyard.org/skippy.php
COMMENT=	Fullscreen task switcher for X11	

USE_X11=		yes

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/skippyrc-default ${EGDIR}/skippyrc

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
