# $NetBSD: Makefile,v 1.2 2001/12/17 14:47:03 tron Exp $

DISTNAME=	xterm-164
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://dickey.his.com/xterm/xterm.html
COMMENT=	Latest terminal emulator for the X Window System

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD X11 distribution

USE_IMAKE=	YES

INSTALL_FILE=	${WRKDIR}/INSTALL
DEINSTALL_FILE=	${INSTALL_FILE}

post-extract:
	@${MKDIR} ${WRKSRC}/X11
	@${LN} -s ${FILESDIR}/Xpoll.h ${WRKSRC}/X11

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
