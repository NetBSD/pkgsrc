# $NetBSD: Makefile,v 1.1 2002/11/08 21:08:02 is Exp $
#

DISTNAME=	lmclock-1.0
CATEGORIES=	time,x11
MASTER_SITES=	http://pantransit.reptiles.org/prog/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://pantransit.reptiles.org/prog/
COMMENT=	hard-coded Xerox Lisp machine clock clone

post-extract:
	${TOUCH} ${WRKSRC}/lmclock.man

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

.include "../../mk/bsd.pkg.mk"
