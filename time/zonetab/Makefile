# $NetBSD: Makefile,v 1.6 2015/01/01 11:31:12 dholland Exp $

DISTNAME=	zonetab-0
CATEGORIES=	time
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	NetBSD zone.tab file

NO_BUILD=	yes

# Installs NetBSD's zone data, not probably that useful elsewhere.
ONLY_FOR_PLATFORM=	NetBSD-*-*

ZTDIR=	${PREFIX}/share/examples/zoneinfo

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${ZTDIR}
	${INSTALL_DATA} ${FILESDIR}/zone.tab ${DESTDIR}${ZTDIR}

.include "../../mk/bsd.pkg.mk"
