# $NetBSD: Makefile,v 1.7 2006/02/05 23:11:12 joerg Exp $
#

DISTNAME=	xtu-1.2
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://core.de/~coto/projects/xtu/

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://core.de/~coto/projects/xtu/
COMMENT=	Small configurable X11 analog clock

INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

do-build:
	cd ${WRKSRC} && ${CC} *.c -o xtu -I${X11BASE}/include ${X11_LDFLAGS} -lX11 -lXext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtu ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
