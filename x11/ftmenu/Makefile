# $NetBSD: Makefile,v 1.1.1.1 2008/05/13 21:36:14 sborrill Exp $
#

DISTNAME=	ftmenu-0.3

CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ftmenu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ftmenu.sourceforge.net/
COMMENT=	Fluxbox Tray Menu

GNU_CONFIGURE=		YES

USE_LANGUAGES+=	c c++

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ftmenu ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/ftmenu
	${INSTALL_DATA} ${WRKSRC}/img/fb.xpm ${PREFIX}/share/ftmenu/fb.xpm

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
