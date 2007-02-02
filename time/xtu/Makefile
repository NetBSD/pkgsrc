# $NetBSD: Makefile,v 1.8 2007/02/02 00:00:45 joerg Exp $
#

DISTNAME=	xtu-1.2
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://core.de/~coto/projects/xtu/

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://core.de/~coto/projects/xtu/
COMMENT=	Small configurable X11 analog clock

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} *.c -o xtu -I${X11BASE}/include ${X11_LDFLAGS} -lX11 -lXext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtu ${PREFIX}/bin/

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
