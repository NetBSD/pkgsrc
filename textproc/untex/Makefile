# $NetBSD: Makefile,v 1.4 2003/03/29 12:42:42 jmmv Exp $
#

DISTNAME=	untex-1.3
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	ftp://hal6000.uni-duisburg.de/pub/source/

MAINTAINER=	packages@netbsd.org
COMMENT=	remove LaTeX commands

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/untex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/untex.man ${PREFIX}/man/man1/untex.1

.include "../../mk/bsd.pkg.mk"
