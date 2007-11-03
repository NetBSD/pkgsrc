# $NetBSD: Makefile,v 1.1.1.1 2007/11/03 21:46:38 drochner Exp $

DISTNAME=	zonetab-0
CATEGORIES=	time
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	zone.tab file

NO_CHECKSUM=	yes
NO_BUILD=	yes

# install path is hardwired
ONLY_FOR_PLATFORM=	NetBSD-*-*

ZTDIR=	${PREFIX}/share/examples/zoneinfo
do-install:
	${INSTALL_DATA_DIR} ${ZTDIR}
	${INSTALL_DATA} ${FILESDIR}/zone.tab ${ZTDIR}

.include "../../mk/bsd.pkg.mk"
