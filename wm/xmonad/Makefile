# $NetBSD: Makefile,v 1.7 2016/01/04 12:45:36 szptvlfn Exp $

DISTNAME=	xmonad-0.12
PKGNAME=	${DISTNAME}
CATEGORIES=	wm

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Tiling window manager
LICENSE=	modified-bsd

# don't need default binary
SUBST_CLASSES+=	1
SUBST_STAGE.1=	pre-patch
SUBST_FILES.1=	xmonad.cabal
SUBST_SED.1=	-e "s|executable xmonad|executable xmonad+    buildable: False|"

SUBST_CLASSES+=	2
SUBST_STAGE.2=	post-patch
SUBST_FILES.2=	xmonad.cabal
SUBST_FILTER_CMD.2=	${TR} '+' \\n

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/xmonad.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-setlocale/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
