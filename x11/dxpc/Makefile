# $NetBSD: Makefile,v 1.8 1998/08/20 15:17:33 tsarna Exp $
#

DISTNAME=		dxpc-3.7.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://ccwf.cc.utexas.edu/~zvonler/dxpc/

GNU_CONFIGURE=		yes
USE_X11=		yes

post-install:
	@strip ${PREFIX}/bin/dxpc

.include "../../mk/bsd.pkg.mk"
