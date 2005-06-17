# $NetBSD: Makefile,v 1.12 2005/06/17 03:50:38 jlam Exp $

DISTNAME=		cal-3.5
PKGREVISION=		1
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/shell/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Enhanced color version of standard calendar utility

WRKSRC=			${WRKDIR}/cal-3.5/source
MAKEFILE=		makefile.unx
BUILD_TARGET=		cal

PKG_SYSCONFSUBDIR=	cal
CFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
EGDIR=			${PREFIX}/share/examples/cal
# CONF_FILES not used as calcol and caldat are optional.

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cal ${PREFIX}/bin/cal
	${INSTALL_MAN}  ${WRKSRC}/cal.1 ${PREFIX}/man/man1/cal.1
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.col ${EGDIR}/calcol
	${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.dat ${EGDIR}/caldat

.include "../../mk/bsd.pkg.mk"
