# $NetBSD: Makefile,v 1.4 1998/04/15 10:38:59 agc Exp $
# FreeBSD Id: Makefile,v 1.7 1996/11/18 09:56:45 asami Exp 
#

DISTNAME=	xsnow-1.40
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	is@netbsd.org

USE_IMAKE=	yes

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man6
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include "../../mk/bsd.pkg.mk"
