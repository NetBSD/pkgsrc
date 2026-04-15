# $NetBSD: Makefile,v 1.1 2026/04/15 08:47:51 kikadf Exp $

DISTNAME=	wvkbd-0.19.4
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_GITHUB:=jjsullivan5196/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/jjsullivan5196/wvkbd/
COMMENT=	On-screen keyboard for wlroots
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config

SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	pre-configure
SUBST_MESSAGE.cfg=	Fix config.mk
SUBST_FILES.cfg+=	config.mk
SUBST_SED.cfg+=		-e '/^PREFIX/s/=/?=/'
SUBST_SED.cfg+=		-e '/^CFLAGS/s/=/+=/'
SUBST_SED.cfg+=		-e '/^MANPREFIX/s/share\///'

SUBST_CLASSES+=		mf
SUBST_STAGE.mf=		pre-configure
SUBST_MESSAGE.mf=	Fix Makefile
SUBST_FILES.mf+=	Makefile
SUBST_SED.mf+=		-e '/^PKGS/s/$$/ epoll-shim/'

CFLAGS+=	-I/usr/pkg/include/libepoll-shim

.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../devel/input-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
