# $NetBSD: Makefile,v 1.13 2003/08/31 16:40:51 kei Exp $
#

DISTNAME=	xcolorsel-1.1a-src
PKGNAME=	xcolorsel-1.1a
PKGREVISION=	1
WRKSRC=		${WRKDIR}/xcolorsel
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	perry@NetBSD.org
COMMENT=	Browse and select named X colors from rgb.txt

USE_BUILDLINK2=	yes
USE_IMAKE=	yes
XAW_TYPE?=	3d

.include "../../mk/bsd.prefs.mk"

# We need at least Xaw3d to compile this package.
.if (${XAW_TYPE} == standard || ${XAW_TYPE} == neXtaw)
XAW_TYPE=	3d
.endif

.include "../../mk/xaw.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
