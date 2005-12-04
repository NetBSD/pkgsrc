# $NetBSD: Makefile,v 1.14 2005/12/04 00:58:22 joerg Exp $

DISTNAME=	xvattr-1.3
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	veego@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	Modify Xv attributes

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_TOOLS+=		pod2man

.include "../../mk/bsd.prefs.mk"

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
