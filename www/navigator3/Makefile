# $NetBSD: Makefile,v 1.1.1.1 1999/07/21 23:09:01 garbled Exp $

DISTNAME=		netscape-v304-export.x86-unknown-bsd
PKGNAME=		navigator3-3.04
CATEGORIES=		www
MASTER_SITES=		ftp://archive:oldies@archive.netscape.com/archive/navigator/3.04/shipping/english/unix/bsdi11/navigator_complete/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.netscape.com

ONLY_FOR_PLATFORM=	*-*-i386

MIRROR_DISTFILE=	no
NO_CDROM=		Licensed product
NO_WRKSUBDIR=		yes
USE_X11BASE=		yes
SCRIPTS_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}
NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${X11BASE}/share/netscape
	${INSTALL_DATA_DIR} ${X11BASE}/share/netscape/nls
	${INSTALL_DATA_DIR} ${X11BASE}/share/netscape/java
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${X11BASE}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/netscape.bin ${X11BASE}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/movemail ${X11BASE}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/movemail.bin ${X11BASE}/bin
	${INSTALL_DATA} ${WRKSRC}/nls/C ${X11BASE}/share/netscape/nls
	${INSTALL_DATA} ${WRKSRC}/nls/nls.dir ${X11BASE}/share/netscape/nls
	${INSTALL_DATA} ${WRKSRC}/java_301 ${X11BASE}/share/netscape/java
	${INSTALL_DATA} ${WRKSRC}/mailcap ${X11BASE}/share/netscape

.include "../../mk/bsd.pkg.mk"
