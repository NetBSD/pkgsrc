# $NetBSD: Makefile,v 1.4 2003/01/03 22:22:09 jmmv Exp $
# FreeBSD Id: Makefile,v 1.5 1997/05/12 06:33:23 max Exp
#

DISTNAME=		cal-3.5
PKGREVISION=		1
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/shell/}

MAINTAINER=		packages@netbsd.org
COMMENT=		Enhanced color version of standard calendar utility

WRKSRC=			${WRKDIR}/cal-3.5/source
MAKEFILE=		makefile.unx
ALL_TARGET=		cal

PKG_SYSCONFSUBDIR=	cal
CFLAGS+=		-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\"\\\"
EGDIR=			${PREFIX}/share/examples/cal
# CONF_FILES not used as calcol and caldat are optional.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cal ${PREFIX}/bin/cal
	${INSTALL_MAN}  ${WRKSRC}/cal.1 ${PREFIX}/man/man1/cal.1
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.col ${EGDIR}/calcol
	${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.dat ${EGDIR}/caldat

.include "../../mk/bsd.pkg.mk"
