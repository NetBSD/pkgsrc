# $NetBSD: Makefile,v 1.1 2026/04/15 08:49:58 kikadf Exp $

DISTNAME=	wev-1.1.0
CATEGORIES=	wayland
MASTER_SITES=	https://git.sr.ht/~sircmpwn/wev/archive/
DIST_SUBDIR=	wev
DISTFILES=	${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://sr.ht/~sircmpwn/wev/
COMMENT=	Wayland event viewer
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fix man path
SUBST_FILES.man+=	Makefile
SUBST_SED.man+=		-e '/^MANDIR/s/SHAREDIR/PREFIX/'

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../devel/input-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
