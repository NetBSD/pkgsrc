# $NetBSD: Makefile,v 1.1.1.1 2005/05/04 16:14:10 drochner Exp $
#

DISTNAME=		gromit-20041213
CATEGORIES=		x11
MASTER_SITES=		http://www.home.unix-ag.org/simon/gromit/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.home.unix-ag.org/simon/gromit/
COMMENT=		Text marker tool for the X11 screen

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gromit ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gromit
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gromit

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
