# $NetBSD: Makefile,v 1.2 2026/08/04 20:29:18 wiz Exp $

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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../devel/input-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
