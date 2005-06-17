# $NetBSD: Makefile,v 1.9 2005/06/17 03:50:38 jlam Exp $
#

DISTNAME=	untex-1.3
CATEGORIES=	textproc
MASTER_SITES=	ftp://hal6000.uni-duisburg.de/pub/source/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Remove LaTeX commands

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/untex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/untex.man ${PREFIX}/man/man1/untex.1

.include "../../mk/bsd.pkg.mk"
