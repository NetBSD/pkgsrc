# $NetBSD: Makefile,v 1.11 2004/08/16 04:53:46 minskim Exp $

DISTNAME=	${PKGBASE}
PKGNAME=	xterm-196
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dickey.his.com/xterm/xterm.html
COMMENT=	Latest terminal emulator for the X Window System

DIST_SUBDIR=	${PKGNAME}

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_X11=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
INSTALL_FILE=	${WRKDIR}/INSTALL
DEINSTALL_FILE=	${INSTALL_FILE}

pre-build:
	@${SED} -e 's#@MV@#${MV}#g' \
	  -e 's#@LOCALBASE@#${LOCALBASE}#g' \
	  -e 's#@PREFIX@#${PREFIX}#g' \
	  ${PKGDIR}/INSTALL >${INSTALL_FILE}

pre-install:
	${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL
.endif

.include "../../mk/bsd.pkg.mk"
