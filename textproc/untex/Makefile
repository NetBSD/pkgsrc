# $NetBSD: Makefile,v 1.7 2003/07/21 17:27:54 martti Exp $
#

DISTNAME=	untex-1.3
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	ftp://hal6000.uni-duisburg.de/pub/source/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Remove LaTeX commands

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/untex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/untex.man ${PREFIX}/man/man1/untex.1

.include "../../mk/bsd.pkg.mk"
