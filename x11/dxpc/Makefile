# $NetBSD: Makefile,v 1.6 1998/06/22 13:20:57 agc Exp $
#

DISTNAME=		dxpc-3.7.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=		frueauf@netbsd.org

GNU_CONFIGURE=		yes
USE_X11=		yes

post-install:
	@strip ${PREFIX}/bin/dxpc

.include "../../mk/bsd.pkg.mk"
