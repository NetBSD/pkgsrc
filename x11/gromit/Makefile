# $NetBSD: Makefile,v 1.8 2006/03/04 21:31:09 jlam Exp $
#

DISTNAME=		gromit-20041213
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		http://www.home.unix-ag.org/simon/gromit/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.home.unix-ag.org/simon/gromit/
COMMENT=		Text marker tool for the X11 screen

USE_TOOLS+=		pkg-config
INSTALLATION_DIRS=	bin

LDFLAGS+=		-lX11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gromit ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gromit
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gromit

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
