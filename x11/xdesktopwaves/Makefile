# $NetBSD: Makefile,v 1.3 2005/04/11 21:48:15 tv Exp $
#

DISTNAME=	xdesktopwaves-1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xdesktopwaves/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://xdesktopwaves.sourceforge.net/
COMMENT=	Simulates water waves on the X Windows desktop

USE_DIRS+=		xdg-1.1
USE_X11=		YES

MAKE_FLAGS+=		CFLAGS="${CFLAGS}"
MAKE_FLAGS+=		LFLAGS="${LDFLAGS}"

INSTALLATION_DIRS=	bin man/man1 share/doc/xdesktopwaves

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdesktopwaves ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/xdesktopwaves.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xdesktopwaves/
	${INSTALL_DATA} ${WRKSRC}/xdesktopwaves.xpm ${PREFIX}/share/pixmaps/

.include "../../mk/bsd.pkg.mk"
