# $NetBSD: Makefile,v 1.3 1999/10/20 11:01:17 agc Exp $

DISTNAME=	dclock
PKGNAME=	dclock-4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	packages@netbsd.org

USE_X11BASE=	yes
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH} -
WRKSRC=		${WRKDIR}

MAKE_ENV+=	CC="${CC}"

.include "../../mk/bsd.pkg.mk"
