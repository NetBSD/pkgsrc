# $NetBSD: Makefile,v 1.14 2017/08/16 20:45:46 wiz Exp $
#

DISTNAME=	lmclock-1.2
PKGREVISION=	1
CATEGORIES=	time x11
MASTER_SITES=	${MASTER_SITE_FREEBSD}

MAINTAINER=	is@NetBSD.org
#HOMEPAGE=	http://pantransit.reptiles.org/prog/
COMMENT=	Hard-coded Xerox Lisp machine clock clone

post-extract:
	${TOUCH} ${WRKSRC}/lmclock.man

USE_IMAKE=		YES

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
