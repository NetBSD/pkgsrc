# $NetBSD: Makefile,v 1.2 2020/07/28 14:23:37 pin Exp $

DISTNAME=	FrankenWM-1.0.22
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=sulami/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sulami/FrankenWM/
COMMENT=	Dynamic tiling window manager
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c99

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
MAKE_ENV+=		MANPREFIX=${PREFIX}/${PKGMANDIR}

DEPENDS+=	dmenu-[0-9]*:../../x11/dmenu

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
