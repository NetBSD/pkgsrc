# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:38 jlam Exp $
#

DISTNAME=	xtu-1.2
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
