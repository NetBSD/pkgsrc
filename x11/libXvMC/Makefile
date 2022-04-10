# $NetBSD: Makefile,v 1.20 2022/04/10 08:53:17 nia Exp $

DISTNAME=		libXvMC-1.0.13
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		XVideo Motion Compensation Library
LICENSE=		mit

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xvmc.pc.in
PKGCONFIG_OVERRIDE+=	xvmc-wrapper.pc.in

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

X11_LIB_NAME?=		libXvMC
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../meta-pkgs/modular-xorg/hacks.mk"
BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
