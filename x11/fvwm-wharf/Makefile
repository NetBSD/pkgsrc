# $NetBSD: Makefile,v 1.9 2004/04/24 15:58:44 snj Exp $

DISTNAME=		AfterStep-1.0
PKGNAME=		fvwm-wharf-1.0
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.afterstep.org/pub/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.afterstep.org/
COMMENT=		Copy of AfterStep's Wharf compatible with fvwm2

USE_BUILDLINK3=		YES
USE_IMAKE=		YES
# We don't want the '-a' flag
XMKMF=			${XMKMF_CMD}

post-configure:
	cd ${WRKSRC}; ${MAKE} Makefiles

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modules/Wharf/Wharf ${PREFIX}/bin/Fvwm-Wharf
	${INSTALL_MAN} ${WRKSRC}/modules/Wharf/Wharf.man ${PREFIX}/man/man1/Fvwm-Wharf.1

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
