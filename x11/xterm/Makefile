# $NetBSD: Makefile,v 1.17 2005/02/16 22:13:47 reed Exp $

DISTNAME=	xterm-200
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dickey.his.com/xterm/xterm.html
COMMENT=	Latest terminal emulator for the X Window System

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_X11=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

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
