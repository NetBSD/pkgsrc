# $NetBSD: Makefile,v 1.1 2026/04/15 07:55:14 kikadf Exp $

DISTNAME=	swappy-1.8.0
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_GITHUB:=jtheoof/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/jtheoof/swappy
COMMENT=	Screenshot tool for Wayland
LICENSE=	mit

USE_TOOLS+=	pkg-config
DEPENDS+=	wl-clipboard-[0-9]*:../../wayland/wl-clipboard

SUBST_CLASSES+=		nogit
SUBST_STAGE.nogit=	pre-configure
SUBST_MESSAGE.nogit=	Set version
SUBST_FILES.nogit+=	meson.build
SUBST_SED.nogit+=	-e 's/git =/\#git =/g'
SUBST_SED.nogit+=	-e 's/git.found()/false/g'

.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../mk/bsd.pkg.mk"
