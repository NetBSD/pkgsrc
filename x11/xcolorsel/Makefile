# $NetBSD: Makefile,v 1.17 2005/04/11 21:48:14 tv Exp $
#

DISTNAME=	xcolorsel-1.1a-src
PKGNAME=	xcolorsel-1.1a
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	perry@NetBSD.org
COMMENT=	Browse and select named X colors from rgb.txt

WRKSRC=		${WRKDIR}/xcolorsel
USE_IMAKE=	yes
XAW_TYPE?=	3d

.include "../../mk/bsd.prefs.mk"

# We need at least Xaw3d to compile this package.
.if (${XAW_TYPE} == standard || ${XAW_TYPE} == neXtaw)
XAW_TYPE=	3d
.endif

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
