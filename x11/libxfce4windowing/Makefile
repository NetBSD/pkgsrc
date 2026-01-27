# $NetBSD: Makefile,v 1.19 2026/01/27 08:40:59 wiz Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4windowing-4.20.5
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/xfce/libxfce4windowing/${PKGVERSION_NOREV:R}/

COMMENT=	Xfce window management library

USE_TOOLS+=		pkg-config
REPLACE_PYTHON+=	xdt-gen-visibility

MESON_ARGS+=		-Dx11=enabled
# For build consistency; we don't need vala for our purposes, and if it happens
# to be found in the environment, it will get auto-enabled and PLIST differences
# occur.
MESON_ARGS+=		-Dvala=disabled
# Don't bother building tests as part of the general package. This causes build
# failures on platforms with older GCC releases, e.g., NetBSD 9.x with GCC 7.5.
MESON_ARGS+=		-Dtests=false

PKGCONFIG_OVERRIDE+=	libxfce4windowing/libxfce4windowing-0.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4windowing/libxfce4windowing-x11-0.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4windowingui/libxfce4windowingui-0.pc.in

TOOL_DEPENDS+=	xfce4-dev-tools>=4.20.0:../../devel/xfce4-dev-tools

.include "../../devel/meson/build.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/libdisplay-info/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
