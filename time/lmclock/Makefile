# $NetBSD: Makefile,v 1.8 2006/02/05 23:11:10 joerg Exp $
#

DISTNAME=	lmclock-1.2
PKGREVISION=	1
CATEGORIES=	time x11
MASTER_SITES=	http://pantransit.reptiles.org/prog/

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://pantransit.reptiles.org/prog/
COMMENT=	Hard-coded Xerox Lisp machine clock clone

post-extract:
	${TOUCH} ${WRKSRC}/lmclock.man

USE_IMAKE=		YES

.include "../../mk/bsd.pkg.mk"
