# $NetBSD: Makefile,v 1.8 2004/01/20 12:26:50 agc Exp $
#

DISTNAME=	untex-1.3
CATEGORIES=	textproc
MASTER_SITES=	ftp://hal6000.uni-duisburg.de/pub/source/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Remove LaTeX commands

WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/untex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/untex.man ${PREFIX}/man/man1/untex.1

.include "../../mk/bsd.pkg.mk"
