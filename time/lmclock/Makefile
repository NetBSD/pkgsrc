# $NetBSD: Makefile,v 1.7 2005/03/23 22:32:04 is Exp $
#

DISTNAME=	lmclock-1.2
PKGREVISION=	0
CATEGORIES=	time x11
MASTER_SITES=	http://pantransit.reptiles.org/prog/

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://pantransit.reptiles.org/prog/
COMMENT=	Hard-coded Xerox Lisp machine clock clone

post-extract:
	${TOUCH} ${WRKSRC}/lmclock.man

USE_IMAKE=		YES

.include "../../mk/bsd.pkg.mk"
