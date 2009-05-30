# $NetBSD: Makefile,v 1.11 2009/05/30 00:56:11 zafer Exp $
#

DISTNAME=	lmclock-1.2
PKGREVISION=	1
CATEGORIES=	time x11
MASTER_SITES=	${MASTER_SITE_FREEBSD}

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://pantransit.reptiles.org/prog/
COMMENT=	Hard-coded Xerox Lisp machine clock clone

PKG_DESTDIR_SUPPORT=	user-destdir

post-extract:
	${TOUCH} ${WRKSRC}/lmclock.man

USE_IMAKE=		YES

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
