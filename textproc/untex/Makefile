# $NetBSD: Makefile,v 1.2 2001/02/17 17:37:54 wiz Exp $
#

DISTNAME=	untex-1.3
CATEGORIES=	textproc
MASTER_SITES=	ftp://hal6000.uni-duisburg.de/pub/source/

MAINTAINER=	packages@netbsd.org
COMMENT=	remove LaTeX commands

NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/untex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/untex.man ${PREFIX}/man/man1/untex.1

.include "../../mk/bsd.pkg.mk"
