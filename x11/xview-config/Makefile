# $NetBSD: Makefile,v 1.6 2000/03/16 14:20:03 wiz Exp $
# $FreeBSD Id: Makefile,v 1.9 1998/05/04 03:34:50 steve Exp
#

DISTNAME=	xview3.2p1-X11R6
PKGNAME=	xview-config-3.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org

MIRROR_DISTFILE= no
EXTRACT_ELEMENTS=	xview3.2p1-X11R6/config
WRKSRC=      	${WRKDIR}/${EXTRACT_ELEMENTS}
USE_IMAKE=	yes
NO_BUILD=	yes

post-extract:
	@${CHMOD} -R go+rX ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
