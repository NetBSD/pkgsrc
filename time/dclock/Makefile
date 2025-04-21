# $NetBSD: Makefile,v 1.20 2025/04/21 21:29:16 wiz Exp $

DISTNAME=	dclock
PKGNAME=	dclock-4
PKGREVISION=	1
CATEGORIES=	time x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Digital clock for X

CONFLICTS+=	ivtools-[0-9]*

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
