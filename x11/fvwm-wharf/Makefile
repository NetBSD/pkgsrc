# $NetBSD: Makefile,v 1.1 1998/08/23 07:34:17 garbled Exp $

DISTNAME=		AfterStep-1.0
PKGNAME=		fvwm-wharf-1.0
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.afterstep.org/pub/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.afterstep.org

DEPENDS=		xpm-3.4k:../../graphics/xpm

USE_X11=		yes

do-configure:
	(cd ${WRKSRC} ; xmkmf ; make Makefiles)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modules/Wharf/Wharf ${PREFIX}/bin/Fvwm-Wharf
	${INSTALL_MAN} ${WRKSRC}/modules/Wharf/Wharf.man ${PREFIX}/man/man1/Fvwm-Wharf.1

.include "../../mk/bsd.pkg.mk"
