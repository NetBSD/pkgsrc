# $NetBSD: Makefile,v 1.6 2003/03/29 12:42:43 jmmv Exp $
#

DISTNAME=	dclock
PKGNAME=	dclock-4
WRKSRC=		${WRKDIR}
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	Digital clock for X

CONFLICTS+=	ivtools-*

USE_X11BASE=	yes

MAKE_ENV+=	CC="${CC}"

.include "../../mk/bsd.pkg.mk"
