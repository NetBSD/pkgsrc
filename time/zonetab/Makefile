# $NetBSD: Makefile,v 1.5 2013/04/06 03:45:26 rodent Exp $

DISTNAME=	zonetab-0
CATEGORIES=	time
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	NetBSD zone.tab file

NO_BUILD=	yes

# install path is hardwired
ONLY_FOR_PLATFORM=	NetBSD-*-*

ZTDIR=	${PREFIX}/share/examples/zoneinfo

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${ZTDIR}
	${INSTALL_DATA} ${FILESDIR}/zone.tab ${DESTDIR}${ZTDIR}

.include "../../mk/bsd.pkg.mk"
