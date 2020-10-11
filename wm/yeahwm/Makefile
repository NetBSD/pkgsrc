# $NetBSD: Makefile,v 1.1 2020/10/11 08:56:37 nia Exp $

DISTNAME=	yeahwm_0.3.5
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	wm
MASTER_SITES=	http://phrat.de/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://phrat.de/
COMMENT=	Minimal X window manager with BeOS-like tabbed titles
LICENSE=	evilwm-license

WRKSRC=		${WRKDIR}/yeahwm-${PKGVERSION_NOREV}

MAKE_FLAGS+=	CC=${CC}
MAKE_FLAGS+=	XROOT=${X11BASE}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yeahwm \
		${DESTDIR}${PREFIX}/bin/yeahwm
	${INSTALL_MAN} ${WRKSRC}/yeahwm.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/yeahwm.1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
