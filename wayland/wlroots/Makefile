# $NetBSD: Makefile,v 1.4 2026/08/11 17:32:34 wiz Exp $

DISTNAME=		wlroots-0.20.2
CATEGORIES=		wayland
MASTER_SITE_GITLAB=	https://gitlab.freedesktop.org/
MASTER_SITES=		${MASTER_SITE_GITLAB:=wlroots/}
GITLAB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		kikadf@NetBSD.org
HOMEPAGE=		https://gitlab.freedesktop.org/wlroots/wlroots
COMMENT=		Wayland compositor library
LICENSE=		mit

USE_TOOLS+=		pkg-config
UDEV_REQUIRED=		yes

MESON_ARGS+=		-Dallocators=gbm

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing pathes
SUBST_FILES.path+=	xcursor/xcursor.c
SUBST_VARS.path+=	PREFIX X11BASE

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 110000
PKG_FAIL_REASON+=	"DRM_IOCTL_GET_UNIQUE is not allowed on render nodes"
.endif

BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings

.include "options.mk"

.include "../../devel/meson/build.mk"
.include "../../devel/libopeninput/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
PREFER.MesaLib=	pkgsrc	# glesv2
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glslang/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libliftoff/buildlink3.mk"
.include "../../graphics/vulkan-loader/buildlink3.mk"
.include "../../sysutils/hwdata/buildlink3.mk"
.include "../../sysutils/seatd/buildlink3.mk"
.include "../../x11/libdisplay-info/buildlink3.mk"
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.129
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xcb-util-errors/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../mk/udev.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
