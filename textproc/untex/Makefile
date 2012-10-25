# $NetBSD: Makefile,v 1.13 2012/10/25 06:57:05 asau Exp $
#

DISTNAME=	untex-1.3
CATEGORIES=	textproc
MASTER_SITES=	ftp://hal6000.uni-duisburg.de/pub/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Remove LaTeX commands

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/untex ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/untex.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/untex.1

.include "../../mk/bsd.pkg.mk"
