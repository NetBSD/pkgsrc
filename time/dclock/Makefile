# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 23:32:16 wiz Exp $
#

DISTNAME=	dclock
PKGNAME=	dclock-4
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	packages@netbsd.org

USE_X11BASE=	yes
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH} -
WRKSRC=		${WRKDIR}

MAKE_ENV+=	CC="${CC}"

.include "../../mk/bsd.pkg.mk"
