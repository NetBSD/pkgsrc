# $NetBSD: Makefile,v 1.3 2003/07/20 10:43:13 martin Exp $
#

DISTNAME=		xtu-1.2
CATEGORIES=		time
MASTER_SITES=		http://core.de/~coto/projects/xtu/

MAINTAINER=		sketch@rd.bbc.co.uk
HOMEPAGE=		http://core.de/~coto/projects/xtu/
COMMENT=		Small configurable X11 analog clock

USE_X11=		yes

do-build:
	cd ${WRKSRC} && ${CC} *.c -o xtu -I${X11BASE}/include ${X11_LDFLAGS} -lX11 -lXext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtu ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
