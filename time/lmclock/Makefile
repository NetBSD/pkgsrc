# $NetBSD: Makefile,v 1.4 2003/03/03 03:23:24 jschauma Exp $
#

DISTNAME=	lmclock-1.1
PKGREVISION=	1
CATEGORIES=	time x11
MASTER_SITES=	http://pantransit.reptiles.org/prog/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://pantransit.reptiles.org/prog/
COMMENT=	hard-coded Xerox Lisp machine clock clone

post-extract:
	${TOUCH} ${WRKSRC}/lmclock.man

USE_IMAKE=		YES

.include "../../mk/bsd.pkg.mk"
