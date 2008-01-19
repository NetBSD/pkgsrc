# $NetBSD: Makefile,v 1.17 2008/01/19 09:16:26 wiz Exp $

DISTNAME=		AfterStep-1.0
PKGNAME=		fvwm-wharf-1.0
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.afterstep.org/pub/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.afterstep.org/
COMMENT=		Copy of AfterStep's Wharf compatible with fvwm2

USE_IMAKE=		YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-configure:
	cd ${WRKSRC}; ${MAKE} Makefiles

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modules/Wharf/Wharf ${PREFIX}/bin/Fvwm-Wharf
	${INSTALL_MAN} ${WRKSRC}/modules/Wharf/Wharf.man ${PREFIX}/${PKGMANDIR}/man1/Fvwm-Wharf.1

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
