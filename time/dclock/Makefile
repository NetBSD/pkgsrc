# $NetBSD: Makefile,v 1.9 2004/01/20 12:27:16 agc Exp $
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

MAKE_ENV+=	CC="${CC}"

.include "../../mk/bsd.pkg.mk"
