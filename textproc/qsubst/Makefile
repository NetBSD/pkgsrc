# $NetBSD: Makefile,v 1.11 2008/02/07 13:24:36 tnn Exp $
#

DISTNAME=	qsubst-20010422
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Query-replace strings in files

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff

WRKSRC=		${WRKDIR}/qsubst

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
