# $NetBSD: Makefile,v 1.13 2020/05/04 14:25:52 nia Exp $
#

DISTNAME=	qsubst-20010422
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Query-replace strings in files

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff

WRKSRC=		${WRKDIR}/qsubst

BUILDLINK_TRANSFORM+=	rm:-Werror

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
