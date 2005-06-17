# $NetBSD: Makefile,v 1.11 2005/06/17 03:50:43 jlam Exp $

DISTNAME=		AfterStep-1.0
PKGNAME=		fvwm-wharf-1.0
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.afterstep.org/pub/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.afterstep.org/
COMMENT=		Copy of AfterStep's Wharf compatible with fvwm2

USE_IMAKE=		YES
# We don't want the '-a' flag
XMKMF=			${XMKMF_CMD}

INSTALLATION_DIRS=	bin man/man1

post-configure:
	cd ${WRKSRC}; ${MAKE} Makefiles

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modules/Wharf/Wharf ${PREFIX}/bin/Fvwm-Wharf
	${INSTALL_MAN} ${WRKSRC}/modules/Wharf/Wharf.man ${PREFIX}/man/man1/Fvwm-Wharf.1

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
