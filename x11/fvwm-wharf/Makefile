# $NetBSD: Makefile,v 1.7 2001/03/11 16:19:47 tron Exp $

DISTNAME=		AfterStep-1.0
PKGNAME=		fvwm-wharf-1.0
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.afterstep.org/pub/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.afterstep.org/
COMMENT=		Copy of AfterStep's Wharf compatible with fvwm2

USE_X11BASE=		YES
USE_XPM=		YES

do-configure:
	(cd ${WRKSRC}; ${X11BASE}/bin/xmkmf; ${MAKE} Makefiles)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modules/Wharf/Wharf ${PREFIX}/bin/Fvwm-Wharf
	${INSTALL_MAN} ${WRKSRC}/modules/Wharf/Wharf.man ${PREFIX}/man/man1/Fvwm-Wharf.1

.include "../../mk/bsd.pkg.mk"
