# $NetBSD: Makefile,v 1.23 2026/01/26 00:00:00 wiz Exp $

DISTNAME=	libXinerama-1.1.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	X PanoramiX extension library

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	xinerama.pc.in

X11_LIB_NAME?=		libXinerama
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../devel/meson/build.mk"
.include "../../meta-pkgs/modular-xorg/hacks.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
