# $NetBSD: Makefile,v 1.7 2001/08/23 04:26:55 jlam Exp $
#

DISTNAME=	xcolorsel-1.1a-src
PKGNAME=	xcolorsel-1.1a
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	perry@netbsd.org
COMMENT=	Browse and select named X colors from rgb.txt

WRKSRC=		${WRKDIR}/xcolorsel
USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

# We need at least Xaw3d to compile this package.
.if (${XAW_TYPE} == standard)
XAW_TYPE=	3d
.endif

.include "../../mk/xaw.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
