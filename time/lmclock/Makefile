# $NetBSD: Makefile,v 1.5 2003/07/17 22:55:02 grant Exp $
#

DISTNAME=	lmclock-1.1
PKGREVISION=	1
CATEGORIES=	time x11
MASTER_SITES=	http://pantransit.reptiles.org/prog/

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://pantransit.reptiles.org/prog/
COMMENT=	hard-coded Xerox Lisp machine clock clone

post-extract:
	${TOUCH} ${WRKSRC}/lmclock.man

USE_IMAKE=		YES

.include "../../mk/bsd.pkg.mk"
