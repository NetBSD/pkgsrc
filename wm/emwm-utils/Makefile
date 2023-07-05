# $NetBSD: Makefile,v 1.5 2023/07/05 14:30:18 vins Exp $

DISTNAME=	emwm-utils-src-1.1
PKGNAME=	${DISTNAME:S,-src,,}
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	https://fastestcode.org/dl/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://fastestcode.org/emwm.html
COMMENT=	Companion utilies for EMWM
LICENSE=	mit

MAKEFLAGS+=	PREFIX=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
USE_TOOLS+=	gmake
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/examples/${PKGBASE}
INSTALLATION_DIRS+=	lib/X11/app-defaults

SETUID_ROOT_PERMS?=	${REAL_ROOT_USER} ${BINGRP} 4755
SPECIAL_PERMS+=		bin/xmsm ${SETUID_ROOT_PERMS}

do-install:
.for p in xmtoolbox xmsm
	${INSTALL_PROGRAM} ${WRKSRC}/src/${p} \
	${DESTDIR}${PREFIX}/bin
.endfor
.for m in xmtoolbox xmsm
	${INSTALL_MAN} ${WRKSRC}/src/${m}.1 \
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/src/xmsession ${DESTDIR}${PREFIX}/bin

post-install:
.for f in XmSm XmToolbox
	${INSTALL_DATA} ${WRKSRC}/src/${f}.ad \
	${DESTDIR}${PREFIX}/lib/X11/app-defaults/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/toolboxrc \
	${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
