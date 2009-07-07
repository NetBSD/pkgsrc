# $NetBSD: Makefile,v 1.12 2009/07/07 20:31:58 joerg Exp $
#

DISTNAME=	untex-1.3
CATEGORIES=	textproc
MASTER_SITES=	ftp://hal6000.uni-duisburg.de/pub/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Remove LaTeX commands

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/untex ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/untex.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/untex.1

.include "../../mk/bsd.pkg.mk"
