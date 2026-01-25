# $NetBSD: Makefile,v 1.11 2026/01/25 15:24:20 vins Exp $

DISTNAME=	emwm-utils-src-1.3.2
PKGNAME=	${DISTNAME:S,-src,,}
CATEGORIES=	wm x11
MASTER_SITES=	https://fastestcode.org/dl/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://fastestcode.org/emwm.html
COMMENT=	Companion utilies for EMWM
LICENSE=	mit

DEPENDS+=	emwm-[0-9]*:../../wm/emwm

USE_TOOLS+=		sed
USE_BSD_MAKEFILE=	yes

RCDIR=		${PREFIX}/lib/X11
DOCDIR=		${PREFIX}/share/doc/emwm/utils

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	pre-configure
SUBST_FILES.pkgsrc=	mf/Makefile.pkgsrc
SUBST_VARS.pkgsrc=	PREFIX PKGMANDIR RCDIR
SUBST_MESSAGE.pkgsrc=	Replacing pkgsrc placeholders

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	SED=${SED:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

.include "../../mk/bsd.prefs.mk"

SETUID_ROOT_PERMS?=	${REAL_ROOT_USER} ${BINGRP} 4755
SPECIAL_PERMS+=		bin/xmsm ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS+=	share/doc/emwm/utils

post-install:
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc	\
		${DESTDIR}${DOCDIR}

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
