# $NetBSD: Makefile,v 1.4 2012/10/08 13:04:32 asau Exp $

DISTNAME=	zonetab-0
CATEGORIES=	time
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	zone.tab file

NO_BUILD=	yes

# install path is hardwired
ONLY_FOR_PLATFORM=	NetBSD-*-*

ZTDIR=	${PREFIX}/share/examples/zoneinfo

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${ZTDIR}
	${INSTALL_DATA} ${FILESDIR}/zone.tab ${DESTDIR}${ZTDIR}

.include "../../mk/bsd.pkg.mk"
