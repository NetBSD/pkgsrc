# $NetBSD: Makefile,v 1.2 1998/07/03 20:59:29 tron Exp $
# $FreeBSD Id: Makefile,v 1.9 1998/05/04 03:34:50 steve Exp
#

DISTNAME=	xview3.2p1-X11R6
PKGNAME=	xview-config-3.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org

EXTRACT_AFTER_ARGS=	xview3.2p1-X11R6/config
WRKSRC=      	${WRKDIR}/${EXTRACT_AFTER_ARGS}
USE_IMAKE=	yes
NO_BUILD=	yes

post-extract:
	@chmod -R go+rX ${WRKDIR}

.include <../../mk/bsd.pkg.mk>
