# $NetBSD: Makefile,v 1.9 1999/01/30 23:18:55 agc Exp $
#

DISTNAME=		dxpc-3.7.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://ccwf.cc.utexas.edu/~zvonler/dxpc/

GNU_CONFIGURE=		yes
USE_X11BASE=		yes

post-install:
	@strip ${PREFIX}/bin/dxpc

.include "../../mk/bsd.pkg.mk"
