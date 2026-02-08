# $NetBSD: Makefile,v 1.21 2026/02/08 06:52:55 wiz Exp $

DISTNAME=		libXScrnSaver-1.2.5
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X11 Screen Saver Library

USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	output/meson-private/xscrnsaver.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

X11_LIB_NAME?=		libXScrnSaver
.include "../../devel/meson/build.mk"
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
