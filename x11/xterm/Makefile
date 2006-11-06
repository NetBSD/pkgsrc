# $NetBSD: Makefile,v 1.32 2006/11/06 10:10:58 joerg Exp $

DISTNAME=	xterm-212
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dickey.his.com/xterm/xterm.html
COMMENT=	Latest terminal emulator for the X Window System

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/wchar.h)
CONFIGURE_ARGS+= --enable-wide-chars
.endif

.include "options.mk"

.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+= --with-setuid
.endif

.if ${OPSYS} == "SunOS"
INSTALL_FILE=	${WRKDIR}/INSTALL
DEINSTALL_FILE=	${INSTALL_FILE}

pre-build:
	${MKDIR} ${INSTALL_FILE:H}
	${SED} -e 's#@MV@#${MV}#g' \
	  -e 's#@LOCALBASE@#${LOCALBASE}#g' \
	  -e 's#@PREFIX@#${PREFIX}#g' \
	  ${PKGDIR}/INSTALL.openwin >${INSTALL_FILE}

pre-install:
	${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
