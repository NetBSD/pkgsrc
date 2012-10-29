# $NetBSD: Makefile,v 1.9 2012/10/29 05:06:07 asau Exp $

DISTNAME=		asnap
PKGNAME=		${DISTNAME}-1.0
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}

MAINTAINER=		he@NetBSD.org
COMMENT=		Takes a snapshot of a region of the screen

WRKSRC=			${WRKDIR}
USE_IMAKE=		yes

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
