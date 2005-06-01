# $NetBSD: Makefile,v 1.4 2005/06/01 18:03:32 jlam Exp $
#

DISTNAME=	xdesktopwaves-1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xdesktopwaves/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://xdesktopwaves.sourceforge.net/
COMMENT=	Simulates water waves on the X Windows desktop

USE_DIRS+=		xdg-1.1

MAKE_FLAGS+=		CFLAGS="${CFLAGS}"
MAKE_FLAGS+=		LFLAGS="${LDFLAGS}"

INSTALLATION_DIRS=	bin man/man1 share/doc/xdesktopwaves

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdesktopwaves ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/xdesktopwaves.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xdesktopwaves/
	${INSTALL_DATA} ${WRKSRC}/xdesktopwaves.xpm ${PREFIX}/share/pixmaps/

.include "../../mk/bsd.pkg.mk"
