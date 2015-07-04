# $NetBSD: Makefile,v 1.19 2015/07/04 16:18:40 joerg Exp $
#

DISTNAME=	dclock
PKGNAME=	dclock-4
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Digital clock for X

CONFLICTS+=	ivtools-*

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
