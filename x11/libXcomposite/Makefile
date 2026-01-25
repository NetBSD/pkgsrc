# $NetBSD: Makefile,v 1.18 2026/01/25 23:56:29 wiz Exp $

DISTNAME=		libXcomposite-0.4.7
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Composite Library
LICENSE=		mit

TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xcomposite.pc.in

X11_LIB_NAME?=		libXcomposite
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../devel/meson/build.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
