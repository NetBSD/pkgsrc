# $NetBSD: Makefile,v 1.8 2004/05/14 11:24:49 grant Exp $

DISTNAME=	${PKGBASE}
PKGNAME=	xterm-188
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

.include "../../mk/bsd.pkg.mk"
