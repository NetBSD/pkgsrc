# $NetBSD: Makefile,v 1.5 2003/06/02 01:16:24 jschauma Exp $
#

DISTNAME=	untex-1.3
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	ftp://hal6000.uni-duisburg.de/pub/source/

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	remove LaTeX commands

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/untex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/untex.man ${PREFIX}/man/man1/untex.1

.include "../../mk/bsd.pkg.mk"
