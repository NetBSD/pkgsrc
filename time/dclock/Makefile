# $NetBSD: Makefile,v 1.8 2003/07/17 22:54:59 grant Exp $
#

DISTNAME=	dclock
PKGNAME=	dclock-4
WRKSRC=		${WRKDIR}
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Digital clock for X

CONFLICTS+=	ivtools-*

USE_X11BASE=	yes

MAKE_ENV+=	CC="${CC}"

.include "../../mk/bsd.pkg.mk"
