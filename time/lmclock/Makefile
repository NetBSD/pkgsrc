# $NetBSD: Makefile,v 1.6 2003/07/21 17:28:41 martti Exp $
#

DISTNAME=	lmclock-1.1
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
