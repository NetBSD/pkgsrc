# $NetBSD: Makefile,v 1.1.1.1 2002/02/27 21:24:58 agc Exp $
#

DISTNAME=		xtu-1.1
CATEGORIES=		time
MASTER_SITES=		http://core.de/~coto/xtu/

MAINTAINER=		sketch@rd.bbc.co.uk
HOMEPAGE=		http://core.de/~coto/xtu/
COMMENT=		Small configurable X11 analog clock

USE_X11=		yes

do-build:
	cd ${WRKSRC} && ${CC} *.c -o xtu -I${X11BASE}/include -L${X11BASE}/lib -Wl,-R${X11BASE}/lib -lX11 -lXext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtu ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
