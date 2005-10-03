# $NetBSD: Makefile,v 1.23 2005/10/03 20:37:12 reed Exp $

DISTNAME=	xterm-205
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	asmodai@in-nomine.org
HOMEPAGE=	http://dickey.his.com/xterm/xterm.html
COMMENT=	Latest terminal emulator for the X Window System

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/x11.buildlink3.mk"

.if exists(/usr/include/wchar.h)
CONFIGURE_ARGS+= --enable-wide-chars
.endif

.include "options.mk"

.if ${OPSYS} == "SunOS"
INSTALL_FILE=	${WRKDIR}/INSTALL
DEINSTALL_FILE=	${INSTALL_FILE}

pre-build:
	@${SED} -e 's#@MV@#${MV}#g' \
	  -e 's#@LOCALBASE@#${LOCALBASE}#g' \
	  -e 's#@PREFIX@#${PREFIX}#g' \
	  ${PKGDIR}/INSTALL.openwin >${INSTALL_FILE}

pre-install:
	${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL
.endif

.include "../../mk/bsd.pkg.mk"
