# $NetBSD: Makefile,v 1.1 2026/08/24 14:25:31 kikadf Exp $

DISTNAME=	waybar-0.15.0
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_GITHUB:=Alexays/}
GITHUB_PROJECT=	Waybar
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	kikadf@NetBSD.org
HOMEPAGE=	https://github.com/Alexays/Waybar/
COMMENT=	Wayland bar for Wlroots based compositors
LICENSE=	mit

USE_CXX_FEATURES+=	filesystem
USE_LANGUAGES=		c c++

USE_TOOLS+=	pkg-config gdbus-codegen

SUBST_CLASSES+=		nogit
SUBST_STAGE.nogit=	pre-configure
SUBST_MESSAGE.nogit=	Set version
SUBST_FILES.nogit+=	meson.build
SUBST_SED.nogit+=	-e 's/git =/\#git =/g'
SUBST_SED.nogit+=	-e 's/git.found()/false/g'

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Set SYSCONFDIR
SUBST_FILES.conf+=	src/config.cpp
SUBST_SED.conf+=	-e 's|SYSCONFDIR "|"${PKG_SYSCONFBASE}|g'

EGDIR=		${PREFIX}/share/examples/waybar
CONF_FILES=	${EGDIR}/config.jsonc ${PKG_SYSCONFDIR}/config.jsonc
CONF_FILES+=	${EGDIR}/style.css ${PKG_SYSCONFDIR}/style.css
CONF_FILES+=	${EGDIR}/power_menu.xml ${PKG_SYSCONFDIR}/power_menu.xml

PKG_SYSCONFSUBDIR=	xdg/waybar
BUILD_DEFS+=		PKG_SYSCONFBASE

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/custom_modules/power_menu.xml \
		${DESTDIR}${EGDIR}

# Linux uses udev for battery plugin
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux"
.include "../../sysutils/libudev/buildlink3.mk"
.endif

.include "../../devel/meson/build.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../devel/chrono-date/buildlink3.mk"
.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../geography/gpsd/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wayland/gtk-layer-shell/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
