# $NetBSD: Makefile,v 1.5 2023/07/05 14:30:18 vins Exp $

DISTNAME=	emwm-src-1.1
PKGNAME=	${DISTNAME:S,-src,,}
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	https://fastestcode.org/dl/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://fastestcode.org/emwm.html
COMMENT=	Enhanced Motif Window Manager
LICENSE=	gnu-lgpl-v2.1

MAKEFLAGS+=	PREFIX=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
USE_TOOLS+=	gmake
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/examples/${PKGBASE}
INSTALLATION_DIRS+=	lib/X11/app-defaults

pre-install:
.for f in system.emwmrc
	${INSTALL_DATA} ${WRKSRC}/src/${f} ${DESTDIR}${PREFIX}/share/examples/emwm/
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/emwm ${DESTDIR}${PREFIX}/bin/emwm
	${INSTALL_MAN} ${WRKSRC}/src/emwm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/emwm.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/Emwm.ad ${DESTDIR}${PREFIX}/lib/X11/app-defaults/Emwm

.include "../../mk/motif.buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
