# $NetBSD: Makefile,v 1.3 2024/12/27 08:20:59 wiz Exp $

PKGREVISION=	2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4windowing-4.20.0
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/xfce/libxfce4windowing/${PKGVERSION_NOREV:R}/

COMMENT=	Xfce window management library

USE_TOOLS+=		pkg-config

MESON_ARGS+=		-Dx11=enabled

PKGCONFIG_OVERRIDE+=	libxfce4windowing/libxfce4windowing-0.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4windowing/libxfce4windowing-x11-0.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4windowingui/libxfce4windowingui-0.pc.in

BUILD_DEPENDS+=	xfce4-dev-tools>=4.20.0:../../devel/xfce4-dev-tools

.include "../../devel/meson/build.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../x11/libdisplay-info/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
