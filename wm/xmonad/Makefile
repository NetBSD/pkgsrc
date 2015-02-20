# $NetBSD: Makefile,v 1.5 2015/02/20 18:35:58 joerg Exp $

DISTNAME=	xmonad-0.11
PKGNAME=	${DISTNAME}
PKGREVISION=	3
CATEGORIES=	wm

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Tiling window manager
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/xmonad.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
