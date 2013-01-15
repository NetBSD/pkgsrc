# $NetBSD: Makefile,v 1.23 2013/01/15 16:21:36 morr Exp $
#

DISTNAME=	xcolorsel-1.1a-src
PKGNAME=	xcolorsel-1.1a
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Browse and select named X colors from rgb.txt

WRKSRC=		${WRKDIR}/xcolorsel
USE_IMAKE=	yes

SUBST_CLASSES+=         xcolorsel
SUBST_STAGE.xcolorsel=        pre-configure
SUBST_MESSAGE.xcolorsel=      Fixing hard-coded paths.
SUBST_FILES.xcolorsel=        RgbText.c
SUBST_SED.xcolorsel+=         -e "s,@X11BASE@,${X11BASE},g"

#this requires Xaw3d
XAW_TYPE=	3d

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
