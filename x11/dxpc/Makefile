# $NetBSD: Makefile,v 1.7 1998/08/08 12:35:42 frueauf Exp $
#

DISTNAME=		dxpc-3.7.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=		packages@netbsd.org

GNU_CONFIGURE=		yes
USE_X11=		yes

post-install:
	@strip ${PREFIX}/bin/dxpc

.include "../../mk/bsd.pkg.mk"
