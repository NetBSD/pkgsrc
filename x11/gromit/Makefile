# $NetBSD: Makefile,v 1.16 2011/01/13 13:39:45 wiz Exp $
#

DISTNAME=		gromit-20041213
PKGREVISION=		8
CATEGORIES=		x11
MASTER_SITES=		http://www.home.unix-ag.org/simon/gromit/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.home.unix-ag.org/simon/gromit/
COMMENT=		Text marker tool for the X11 screen

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
INSTALLATION_DIRS=	bin

LDFLAGS+=	${X11_LDFLAGS} -lX11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gromit ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/gromit
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/gromit

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
