# $NetBSD: Makefile,v 1.4 1998/04/15 10:38:53 agc Exp $
#

DISTNAME=	dxpc-3.7.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=	frueauf@netbsd.org

GNU_CONFIGURE=	yes
USE_X11=	yes

MAN1=		dxpc.1

post-install:
	@strip ${PREFIX}/bin/dxpc

.include "../../mk/bsd.pkg.mk"
