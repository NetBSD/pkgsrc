# $NetBSD: Makefile,v 1.10 1999/04/15 20:39:48 tron Exp $
#

DISTNAME=		dxpc-3.7.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://ccwf.cc.utexas.edu/~zvonler/dxpc/

GNU_CONFIGURE=		yes
USE_X11BASE=		yes

post-install:
	@strip ${PREFIX}/bin/dxpc

.include "../../mk/bsd.pkg.mk"
