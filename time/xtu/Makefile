# $NetBSD: Makefile,v 1.2 2003/03/14 19:37:58 jlam Exp $
#

DISTNAME=		xtu-1.1
CATEGORIES=		time
MASTER_SITES=		http://core.de/~coto/xtu/

MAINTAINER=		sketch@rd.bbc.co.uk
HOMEPAGE=		http://core.de/~coto/xtu/
COMMENT=		Small configurable X11 analog clock

USE_X11=		yes

do-build:
	cd ${WRKSRC} && ${CC} *.c -o xtu -I${X11BASE}/include ${X11_LDFLAGS} -lX11 -lXext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtu ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
