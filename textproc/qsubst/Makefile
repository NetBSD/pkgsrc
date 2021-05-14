# $NetBSD: Makefile,v 1.14 2021/05/14 11:14:42 nia Exp $
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

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
