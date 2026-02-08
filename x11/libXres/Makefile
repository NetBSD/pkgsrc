# $NetBSD: Makefile,v 1.22 2026/02/08 06:57:01 wiz Exp $

DISTNAME=		libXres-1.2.3
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Resource Information Extension Library

USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	output/meson-private/xres.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

X11_LIB_NAME?=		libXres
.include "../../devel/meson/build.mk"
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
