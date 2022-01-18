# $NetBSD: Makefile,v 1.16 2022/01/18 02:48:30 pho Exp $

DISTNAME=	xmonad-0.15
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	wm

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Tiling window manager
LICENSE=	modified-bsd

# don't need default binary (see MESSAGE)
# TODO: This should probably be reconsidered as the default executable
# is now capable of loading custom configuration files.
SUBST_CLASSES+=	1
SUBST_STAGE.1=	post-extract
SUBST_FILES.1=	xmonad.cabal
SUBST_SED.1=	-e "s|executable xmonad|executable xmonad+  buildable: False|"

SUBST_CLASSES+=		2
SUBST_STAGE.2=		pre-configure
SUBST_FILES.2=		xmonad.cabal
SUBST_FILTER_CMD.2=	${TR} '+' \\n

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/xmonad.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../devel/hs-setlocale/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
