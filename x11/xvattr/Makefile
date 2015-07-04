# $NetBSD: Makefile,v 1.22 2015/07/04 16:18:44 joerg Exp $

DISTNAME=	xvattr-1.3
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	Modify Xv attributes
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		pod2man

.include "../../mk/bsd.prefs.mk"

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
