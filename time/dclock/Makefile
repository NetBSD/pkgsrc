# $NetBSD: Makefile,v 1.3 2002/01/27 18:32:34 jlam Exp $
#

DISTNAME=	dclock
PKGNAME=	dclock-4
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	Digital clock for X

USE_X11BASE=	yes
WRKSRC=		${WRKDIR}

MAKE_ENV+=	CC="${CC}"

.include "../../mk/bsd.pkg.mk"
