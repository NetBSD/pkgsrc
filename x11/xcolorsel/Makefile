# $NetBSD: Makefile,v 1.5 2001/02/17 17:07:01 wiz Exp $
#

DISTNAME=	xcolorsel-1.1a-src
PKGNAME=	xcolorsel-1.1a
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	perry@netbsd.org
COMMENT=	Browse and select named X colors from rgb.txt

WRKSRC=		${WRKDIR}/xcolorsel
USE_IMAKE=	yes
USE_XAW=	yes

.include "../../mk/bsd.prefs.mk"

XAW_TYPE?=	3d

.include "../../mk/bsd.pkg.mk"
