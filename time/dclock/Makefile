# $NetBSD: Makefile,v 1.5 2002/03/22 13:26:22 tron Exp $
#

DISTNAME=	dclock
PKGNAME=	dclock-4
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	Digital clock for X

CONFLICTS+=	ivtools-*

USE_X11BASE=	yes
WRKSRC=		${WRKDIR}

MAKE_ENV+=	CC="${CC}"

.include "../../mk/bsd.pkg.mk"
