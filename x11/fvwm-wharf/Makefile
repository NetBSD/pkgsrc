# $NetBSD: Makefile,v 1.4 1999/03/08 10:53:58 agc Exp $

DISTNAME=		AfterStep-1.0
PKGNAME=		fvwm-wharf-1.0
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.afterstep.org/pub/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.afterstep.org/

DEPENDS=		xpm-3.4k:../../graphics/xpm

USE_X11BASE=		yes

do-configure:
	(cd ${WRKSRC} ; xmkmf ; ${MAKE} Makefiles)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modules/Wharf/Wharf ${PREFIX}/bin/Fvwm-Wharf
	${INSTALL_MAN} ${WRKSRC}/modules/Wharf/Wharf.man ${PREFIX}/man/man1/Fvwm-Wharf.1

.include "../../mk/bsd.pkg.mk"
