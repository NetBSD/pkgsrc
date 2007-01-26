# $NetBSD: Makefile,v 1.10 2007/01/26 23:24:02 joerg Exp $
#

DISTNAME=	xdesktopwaves-1.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xdesktopwaves/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xdesktopwaves.sourceforge.net/
COMMENT=	Simulates water waves on the X Windows desktop

USE_DIRS+=		xdg-1.1

MAKE_FLAGS+=		CFLAGS=${CFLAGS:M*:Q}
MAKE_FLAGS+=		LFLAGS=${LDFLAGS:M*:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/xdesktopwaves

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdesktopwaves ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/xdesktopwaves.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xdesktopwaves/
	${INSTALL_DATA} ${WRKSRC}/xdesktopwaves.xpm ${PREFIX}/share/pixmaps/

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
