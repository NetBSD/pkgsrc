# $NetBSD: Makefile,v 1.3 2002/11/09 00:39:58 wiz Exp $
#

DISTNAME=	lmclock-1.1
CATEGORIES=	time x11
MASTER_SITES=	http://pantransit.reptiles.org/prog/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://pantransit.reptiles.org/prog/
COMMENT=	hard-coded Xerox Lisp machine clock clone

post-extract:
	${TOUCH} ${WRKSRC}/lmclock.man

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

.include "../../mk/bsd.pkg.mk"
