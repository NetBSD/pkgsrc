# $NetBSD: Makefile,v 1.10 2004/05/23 20:58:42 danw Exp $
#

DISTNAME=	dclock
PKGNAME=	dclock-4
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Digital clock for X

CONFLICTS+=	ivtools-*

WRKSRC=		${WRKDIR}
USE_X11BASE=	yes
USE_BUILDLINK3=	yes

MAKE_ENV+=	CC="${CC}"

.include "../../mk/bsd.pkg.mk"
