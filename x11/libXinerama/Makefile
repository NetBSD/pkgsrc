# $NetBSD: Makefile,v 1.24 2026/02/08 06:54:46 wiz Exp $

DISTNAME=	libXinerama-1.1.6
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	X PanoramiX extension library

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	output/meson-private/xinerama.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

X11_LIB_NAME?=		libXinerama
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../devel/meson/build.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
