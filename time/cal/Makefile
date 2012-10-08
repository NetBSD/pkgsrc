# $NetBSD: Makefile,v 1.17 2012/10/08 13:04:17 asau Exp $

DISTNAME=		cal-3.5
PKGREVISION=		1
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/shell/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Enhanced color version of standard calendar utility

WRKSRC=			${WRKDIR}/cal-3.5/source
MAKE_FILE=		makefile.unx
BUILD_TARGET=		cal

PKG_SYSCONFSUBDIR=	cal
CFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
EGDIR=			${PREFIX}/share/examples/cal
# CONF_FILES not used as calcol and caldat are optional.

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cal ${DESTDIR}${PREFIX}/bin/cal
	${INSTALL_MAN}  ${WRKSRC}/cal.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cal.1
	${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.col ${DESTDIR}${EGDIR}/calcol
	${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.dat ${DESTDIR}${EGDIR}/caldat

.include "../../mk/bsd.pkg.mk"
