# $NetBSD: Makefile,v 1.5 2000/08/23 23:14:33 tron Exp $

DISTNAME=		AfterStep-1.0
PKGNAME=		fvwm-wharf-1.0
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.afterstep.org/pub/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.afterstep.org/

USE_X11BASE=		YES
USE_XPM=		YES

do-configure:
	(cd ${WRKSRC} ; xmkmf ; ${MAKE} Makefiles)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modules/Wharf/Wharf ${PREFIX}/bin/Fvwm-Wharf
	${INSTALL_MAN} ${WRKSRC}/modules/Wharf/Wharf.man ${PREFIX}/man/man1/Fvwm-Wharf.1

.include "../../mk/bsd.pkg.mk"
