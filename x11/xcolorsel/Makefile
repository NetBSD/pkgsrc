# $NetBSD: Makefile,v 1.19 2006/02/05 23:11:45 joerg Exp $
#

DISTNAME=	xcolorsel-1.1a-src
PKGNAME=	xcolorsel-1.1a
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	perry@NetBSD.org
COMMENT=	Browse and select named X colors from rgb.txt

WRKSRC=		${WRKDIR}/xcolorsel
MAKE_ENV+=	LIBXAW=${LIBXAW:Q}
USE_IMAKE=	yes

.include "../../x11/Xaw3d/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
