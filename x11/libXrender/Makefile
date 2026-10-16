# $NetBSD: Makefile,v 1.21 2026/10/16 20:47:05 wiz Exp $

DISTNAME=		libXrender-0.9.13
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Render Library
LICENSE=		mit

CONFLICTS+=		Xrender-[0-9]*

USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xrender.pc.in

.include "../../devel/meson/build.mk"
.include "../../x11/xorgproto/buildlink3.mk"
BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
