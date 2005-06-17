# $NetBSD: Makefile,v 1.15 2005/06/17 03:50:41 jlam Exp $

DISTNAME=		netscape-v304-export.x86-unknown-bsd
PKGNAME=		navigator3-3.04
CATEGORIES=		www
MASTER_SITES=		ftp://archive.netscape.com/archive/navigator/3.04/shipping/english/unix/bsdi11/navigator_complete/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.netscape.com/
COMMENT=		Netscape Navigator browser, version 3

ONLY_FOR_PLATFORM=	*-*-i386

RESTRICTED=		Licensed product
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}
USE_X11BASE=		YES
SCRIPTS_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}
NO_BUILD=		YES

INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

pre-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/netscape
	${INSTALL_DATA_DIR} ${PREFIX}/share/netscape/nls
	${INSTALL_DATA_DIR} ${PREFIX}/share/netscape/java
	${INSTALL_SCRIPT} ${WRKSRC}/netscape3 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape3.bin ${PREFIX}/bin # XXX
	${INSTALL_SCRIPT} ${WRKSRC}/movemail ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/movemail.bin ${PREFIX}/bin # XXX
	${INSTALL_DATA} ${WRKSRC}/nls/C ${PREFIX}/share/netscape/nls
	${INSTALL_DATA} ${WRKSRC}/nls/nls.dir ${PREFIX}/share/netscape/nls
	${INSTALL_DATA} ${WRKSRC}/java_301 ${PREFIX}/share/netscape/java
	${INSTALL_DATA} ${WRKSRC}/mailcap ${PREFIX}/share/netscape

.include "../../mk/bsd.pkg.mk"
