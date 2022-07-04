# $NetBSD: Makefile,v 1.1 2022/07/04 20:09:05 pin Exp $

DISTNAME=	emwm-src
PKGVER=		1.0a
PKGNAME=	${DISTNAME:S,-src,,}-${PKGVER}
CATEGORIES=	wm
DIST_SUBDIR=	${PKGNAME_NOREV}
MASTER_SITES=	https://fastestcode.org/dl/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://fastestcode.org/emwm.html
COMMENT=	Enhanced Motif Window Manager
LICENSE=	gnu-lgpl-v2.1

MAKEFLAGS+=	PREFIX=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
USE_TOOLS+=	gmake
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/examples/${DISTNAME:S,-src,,}
INSTALLATION_DIRS+=	lib/X11/app-defaults

WRKSRC=	${WRKDIR}/emwm

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
