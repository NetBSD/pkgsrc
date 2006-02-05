# $NetBSD: Makefile,v 1.14 2006/02/05 23:11:09 joerg Exp $
#

DISTNAME=	dclock
PKGNAME=	dclock-4
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Digital clock for X

CONFLICTS+=	ivtools-*

WRKSRC=		${WRKDIR}
USE_X11BASE=	yes

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
