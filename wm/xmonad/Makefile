# $NetBSD: Makefile,v 1.25 2023/11/02 06:37:44 pho Exp $

DISTNAME=	xmonad-0.17.2
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	wm

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Tiling window manager
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/examples/xmonad

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/xmonad.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/man/xmonad.hs ${DESTDIR}${PREFIX}/share/examples/xmonad

.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-setlocale/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
