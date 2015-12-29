# $NetBSD: Makefile,v 1.25 2015/12/29 04:54:39 dholland Exp $

DISTNAME=	xcolorsel-1.1a-src
PKGNAME=	xcolorsel-1.1a
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Browse and select named X colors from rgb.txt

WRKSRC=		${WRKDIR}/xcolorsel
USE_IMAKE=	yes

SUBST_CLASSES+=		xcolorsel
SUBST_STAGE.xcolorsel=		pre-configure
SUBST_MESSAGE.xcolorsel=	Fixing hard-coded paths.
SUBST_FILES.xcolorsel=		RgbText.c
SUBST_SED.xcolorsel+=		-e "s,@X11BASE@,${X11BASE},g"

#this requires Xaw3d
XAW_TYPE=	3d
# does not directly support Xaw3d
BUILDLINK_TRANSFORM+=	l:Xaw:Xaw3d
.PHONY: buildlink-Xaw3d-inc-hack
pre-configure: buildlink-Xaw3d-inc-hack

buildlink-Xaw3d-inc-hack: buildlink-directories
	cd ${BUILDLINK_DIR}/include/X11 && ln -s Xaw3d Xaw

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
