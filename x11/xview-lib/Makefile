# $NetBSD: Makefile,v 1.2 1998/07/03 22:58:34 tron Exp $
# $FreeBSD Id: Makefile,v 1.13 1997/07/17 15:13:03 max Exp
#

DISTNAME=	xview3.2p1-X11R6
PKGNAME=	xview-lib-3.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org

DEPENDS=        xview-config-3.2.1:../../x11/xview-config

USE_IMAKE=	yes

post-install:
	${LDCONFIG} || ${TRUE}

.include <../../mk/bsd.pkg.mk>
